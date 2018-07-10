#pragma once

#include <qwidget.h>
#include <core/VectorImage.h>

class StrokeHandler
{
public:
	StrokeHandler(qf::VectorImage& image);

	// TODO:  Events should be specialized for strokes
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private:
	bool mCurrentlyDrawing;
	qf::Stroke mCurrentStroke;
	qf::VectorImage& mImage;
};
