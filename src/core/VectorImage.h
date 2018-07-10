#pragma once
#include <vector>

#include "Stroke.h"
#include "MathTypes.h"

namespace qf
{
	class VectorImage
	{
	public:
		VectorImage() = default;
		void AddStroke(Stroke&& stroke);
		const std::vector<Stroke>& GetStrokes() const;

	private:
		std::vector<Stroke> mStrokes;
	};
}