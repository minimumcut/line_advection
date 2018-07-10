#include "MainWindow.h"

Canvas::Canvas(StrokeHandler& strokeHandler, const qf::VectorImage& vectorImage) :
	mStrokeHandler(strokeHandler),
	mImage (vectorImage)
{}

void Canvas::mousePressEvent(QMouseEvent* event)
{
	mStrokeHandler.mousePressEvent(event);
}

void Canvas::mouseMoveEvent(QMouseEvent* event)
{
	mStrokeHandler.mouseMoveEvent(event);
}

void Canvas::mouseReleaseEvent(QMouseEvent* event)
{
	mStrokeHandler.mouseReleaseEvent(event);
}

void Canvas::paintEvent(QPaintEvent* event)
{
	
}

void Canvas::resizeEvent(QResizeEvent* event)
{
}
