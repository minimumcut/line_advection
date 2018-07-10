#pragma once
#include <vector>
#include <core/MathTypes.h>

namespace qf
{
	class Point
	{
	public:
		Point(const Vec2f& pos);
		Vec2f GetPosition() const;

	private:
		Vec2f mPos;
	};
}