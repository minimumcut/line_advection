#include "MainWindow.h"

#include "Canvas.h"

MainWindow::MainWindow() :
	mVectorImageTest(),
	mStrokeHandlerTest(mVectorImageTest),
	mCanvas(new Canvas(mStrokeHandlerTest, mVectorImageTest))
{
	setCentralWidget(mCanvas);

	setWindowTitle(tr("Scribble"));
    resize(500, 500);

}

