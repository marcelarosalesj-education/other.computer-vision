#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

class Histogram {
	private:
	string filename = "";
	public:
	Histogram(string f);
	Mat generate();
};

#endif
