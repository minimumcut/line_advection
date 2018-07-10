#include "VectorImage.h"

using namespace qf;

void VectorImage::AddStroke(Stroke&& stroke)
{
	mStrokes.push_back(std::move(stroke));
}

const std::vector<Stroke>& qf::VectorImage::GetStrokes() const
{
	return mStrokes;
}
