#pragma once

#include <utility>
#include <iostream>
#include <optional>

#include <core/Object.h>
#include <core/MathTypes.h>

#include <QPixMap>

namespace qf
{
	template <typename T>
	class PxRaster final
	{
	public:
		PxRaster(size_t width, size_t height) : 
			mWidth(width),
			mHeight(height)
		{
			int type_size = sizeof(T);
			int space = width * height * type_size;
			mData = static_cast<T*>(malloc(space));
		}
		PxRaster(const PxRaster&) = delete;
		PxRaster(PxRaster&& other) :
			mHeight (other.mHeight),
			mWidth (other.mWidth),
			mData (other.mData)
		{
			other.mData = nullptr;
		}
		PxRaster& operator=(const PxRaster&) = delete;
		PxRaster& operator=(PxRaster&& other)
		{
			if (mData != nullptr)
			{
				free(mData);
			}

			mHeight = other.mHeight;
			mWidth = other.mWidth;
			mData = other.mData;
			other.mData = nullptr;
			return *this;
		}

		~PxRaster()
		{
			if (mData != nullptr)
			{
				delete mData;
			}
		}

		const T& GetElem(size_t x, size_t y) const
		{
			return mData[x + y * mWidth];
		}
		
		void SetItem(T item, size_t x, size_t y)
		{
			mData[x + y * mWidth] = item;
		}

		size_t GetWidth() const
		{
			return mWidth;
		}

		size_t GetHeight() const
		{
			return mHeight;
		}

	private:
		size_t mWidth;
		size_t mHeight;
		T* mData;
	};

	class ExrImage final : public Object
	{
	public:
		ExrImage(std::string filename);
		virtual ~ExrImage();
		size_t GetWidth() const;
		size_t GetHeight() const;
		Vec3f GetPixel(size_t x, size_t y) const;
		virtual bool IsNull() const;
	
	private:
		size_t mWidth;
		size_t mHeight;
		float* mData;
	};

	class PxMotionData
	{
	public:
		PxMotionData(Vec2f nextFrameOffset);
		Vec2f GetNextFrameOffset() const;

	private:
		Vec2f mNextFrameOffset;
	};

	class MotionTranslator final : public Object
	{
	public:
		MotionTranslator(std::string motionMap, std::string depthMap, const Mat4f viewMatrix);
		virtual bool IsNull() const;
		const PxRaster<PxMotionData>& GetMotionData() const;

	private:

		void Translate();
		const ExrImage mDepth;
		const ExrImage mMotion;
		const Mat4f mViewMatrix;
		std::optional<PxRaster<PxMotionData>> mMotionData;
	};
}