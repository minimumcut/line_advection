#include "MainWindow.h"

#include <qmouseevent>
#include <core/MathTypes.h>

StrokeHandler::StrokeHandler(qf::VectorImage& image) :
	mCurrentlyDrawing(false),
	mImage(image)
{
}

void StrokeHandler::mousePressEvent(QMouseEvent* event)
{
	if (event->button() != Qt::LeftButton)
	{
		return;
	}

	mCurrentlyDrawing = true;
	mCurrentStroke.AddPoint(qf::Vec2f(event->pos().x(), event->pos().y()));
}

void StrokeHandler::mouseMoveEvent(QMouseEvent* event)
{
	if (!event->buttons() & Qt::LeftButton)
	{
		return;
	}

	if (!mCurrentlyDrawing)
	{
		return;
	}

	mCurrentStroke.AddPoint(qf::Vec2f(event->pos().x(), event->pos().y()));
}

void StrokeHandler::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() != Qt::LeftButton)
	{
		return;
	}

	if (!mCurrentlyDrawing)
	{
		return;
	}

	mCurrentStroke.AddPoint(qf::Vec2f(event->pos().x(), event->pos().y()));
	mImage.AddStroke(std::move(mCurrentStroke));
	mCurrentlyDrawing = false;
}

