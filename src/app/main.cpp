#include <Eigen/Sparse>
#include <iostream>
#include <QApplication>
#include <qimage.h>
#include <qimagewriter.h>

#include <core/MotionTranslator.h>
#include <core/VectorImage.h>

#include "MainWindow.h"

#include "StrokeHandler.h"
#include "Canvas.h"

using namespace qf;

int main(int argc, char **argv) 
{
	QApplication app (argc, argv);
	MainWindow window;
	window.show();
	return app.exec();
#if 0
	std::string testDepth("C:/Users/Ryan/Desktop/line advection/line_advection/sample_data/basic_set/depth/Image0043.exr");
	std::string testMotion("C:/Users/Ryan/Desktop/line advection/line_advection/sample_data/basic_set/mvec/Image0043.exr");
	Mat4f testModelView;
	testModelView << 0.6859206557273865,	0.7276763916015625,  1.4901162970204496e-08, -0.39600732922554016,
					 -0.32401350140571594,	0.3054208755493164,  0.8953956961631775,	 -0.3731383979320526,
					 0.6515582799911499,	-0.6141704320907593, 0.44527143239974976,	 -11.250574111938477,
				     -0.0,					0.0,				 -0.0,					  1.0;
	testModelView = testModelView.inverse().eval();

	Mat4f testProjection;
	testProjection << 1.3032251596450806, 0.0,				  0.0,				   0.0,
					  0.0,				  2.3168447017669678, 0.0,				   0.0,
					  0.0,				  0.0,				  -1.069017767906189,  -2.0706708431243896,
					  0.0,				  0.0,				  -1.0,                0.0;
	testProjection = testProjection.inverse().eval();

	Mat4f mvpInvert = testModelView * testProjection;

	MotionTranslator translator(testMotion, testDepth, mvpInvert);
	const PxRaster<PxMotionData>& data = translator.GetMotionData();		

	QImage img(data.GetWidth(), data.GetHeight(), QImage::Format::Format_RGB32);
	for (size_t x = 0; x < data.GetWidth(); x++)
	{
		for (size_t y = 0; y < data.GetHeight(); y++)
		{
			PxMotionData d = data.GetElem(x, y);
			Vec2f offset = d.GetNextFrameOffset();
			QColor color(std::abs(offset.x()) / 10, std::abs(offset.y()) / 10, 0);
			if(std::abs(color.red()) > 0)
				std::cout << color.red() << "," << color.green();
			img.setPixelColor(QPoint(x,y), color);
		}
	}

	VectorImage image;
	StrokeHandler strokeHandler(image);
	Canvas canvas(strokeHandler, image);

	QImageWriter writer("C:/Users/Ryan/Desktop/line advection output/Output.png", "png");
	bool succeeded = writer.write(img);

    return 0;
#endif
}