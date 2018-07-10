#include "MotionTranslator.h"

#include <qcolor.h>
#include <iostream>
#include <tinyexr.h>

#define TINYEXR_IMPLEMENTATION
#include "tinyexr.h"

using namespace qf;

MotionTranslator::MotionTranslator(std::string motionMap, std::string depthMap, const Mat4f viewMatrix) :
	mDepth (depthMap.c_str()),
	mMotion (motionMap.c_str()),
	mViewMatrix (viewMatrix.inverse())
{
	if (mDepth && mMotion)
	{
		Translate();
	}
}

bool MotionTranslator::IsNull() const
{
	return false;
}

const PxRaster<PxMotionData>& MotionTranslator::GetMotionData() const
{
	return *mMotionData;
}

void MotionTranslator::Translate()
{
	assert(mDepth.GetWidth() == mMotion.GetWidth());
	assert(mDepth.GetHeight() == mMotion.GetHeight());

	const Mat4f viewInverse = mViewMatrix.inverse().eval();
	size_t width = mDepth.GetWidth();
	size_t height = mDepth.GetHeight();

	mMotionData = std::move(PxRaster<PxMotionData>(width, height));
	
	for (size_t x = 0; x < width; x++)
	{
		for (size_t y = 0; y < height; y++)
		{
			const float framerate = 1.f / 24.f;
			const Vec3f velocity = mMotion.GetPixel(x, y);
			const Vec3f depth = mDepth.GetPixel(x, y);

			// Get clip space coordinates of pixel

			const Vec4f clipSpaceCoordinates(x / width, y / height, depth.x(), 1.f);

			// Get worldspace coordinate of current pixel
			const Vec4f worldspacePixel = mViewMatrix * clipSpaceCoordinates;
			// todo: find a better syntax

			const Vec3f worldSpaceOffset = velocity * framerate;

			// Apply motion step to pixel in world space
			const Vec4f newWorldSpaceCoordinate = worldspacePixel + Vec4f(worldSpaceOffset.x(), worldSpaceOffset.y(), worldSpaceOffset.z(), 0.f);

			// Project new pixel back onto screen space
			const Vec4f newClipSpaceCoordinates = viewInverse * newWorldSpaceCoordinate;

			// Calculate, and write out offset
			const Vec4f clipSpaceOffset = clipSpaceCoordinates - newClipSpaceCoordinates;

			// Convert to screenspace offsets
			const Vec2f pxOffset(clipSpaceOffset.x() * width, clipSpaceOffset.y() * height);
			mMotionData->SetItem(PxMotionData(pxOffset), x, y);
		}
	}
}

PxMotionData::PxMotionData(Vec2f nextFrameOffset) :
	mNextFrameOffset (nextFrameOffset)
{}

Vec2f PxMotionData::GetNextFrameOffset() const
{
	return mNextFrameOffset;
}

ExrImage::ExrImage(std::string filename)
{
	// Todo:  check the storage format is correct
	float* out;
	int width;
	int height;
	const char* err;

	// temp:  this outputs alpha -- even though it's not present in the file :(
	int ret = LoadEXR(&out, &width, &height, filename.c_str(), &err);
	
	if (ret)
	{
		std::cout << err << std::endl;
		mData = nullptr;
	}
	else
	{
		mData = out;
		mWidth = width;
		mHeight = height;
	}
}

ExrImage::~ExrImage()
{
	if (mData != nullptr)
	{
		free(mData);
	}
}

size_t ExrImage::GetWidth() const
{
	return mWidth;
}

size_t ExrImage::GetHeight() const
{
	return mHeight;
}

Vec3f ExrImage::GetPixel(size_t x, size_t y) const
{
	const size_t PIXEL_WIDTH = 4;
	float *pxData = &mData[PIXEL_WIDTH * (x + y * mWidth)];
	return Vec3f(pxData[0], pxData[1], pxData[2]);
}

bool ExrImage::IsNull() const
{
	return mData != nullptr;
}
