#pragma once

#include "Canvas.h"

#include <QMainWindow>
#include <core/VectorImage.h>

class Canvas;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

    QString curFile;

private:

	qf::VectorImage mVectorImageTest;
	StrokeHandler mStrokeHandlerTest;
	Canvas* mCanvas;
};