#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

class Histogram {
	private:
	Mat image;
	public:
	Histogram(Mat m);
	Mat generate();
};

#endif
