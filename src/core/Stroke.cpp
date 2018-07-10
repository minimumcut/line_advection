#include "Stroke.h"

using namespace qf;

Stroke::Stroke()
{
}

Stroke::Stroke(Stroke&& other)
{
	mPoints = std::move(other.mPoints);
}

Stroke& Stroke::operator=(Stroke&& other)
{
	mPoints = std::move(other.mPoints);
	return(*this);
}

void Stroke::AddPoint(const Point &p)
{
	mPoints.push_back(p);
}

const std::vector<Point>& Stroke::GetPoints() const
{
	return mPoints;
}
