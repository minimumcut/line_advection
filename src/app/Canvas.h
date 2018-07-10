#pragma once

#include <qwidget.h>
#include "StrokeHandler.h"

#include <core/VectorImage.h>

class Canvas : public QWidget
{
	Q_OBJECT

public:
	Canvas(StrokeHandler& strokeHandler, const qf::VectorImage& vectorImage);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private:
	StrokeHandler& mStrokeHandler;
	
	// TODO:  another class should be wrapping VectorImage, to provide better
	// MVC semantics
	const qf::VectorImage& mImage;
};
