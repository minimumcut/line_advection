#include "MotionTranslator.h"
#include "Point.h"

using namespace qf;

Point::Point(const Vec2f& pos) :
	mPos(pos)
{}

Vec2f Point::GetPosition() const
{
	return mPos;
}
