#pragma once
#include <vector>

#include "Point.h"
#include "MathTypes.h"

namespace qf
{
	class Stroke
	{
	public:
		Stroke();
		Stroke(const Stroke&) = delete;
		Stroke(Stroke&& other);
		Stroke& operator=(const Stroke&) = delete;
		Stroke& operator=(Stroke&& other);

		void AddPoint(const Point& p);
		const std::vector<Point>& GetPoints() const;

	private:
		std::vector<Point> mPoints;
	};
}