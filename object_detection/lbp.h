#ifndef LBP_H
#define LBP_H

#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

class LBP {
	private:
	Mat image;
	Mat result;
	public:
	LBP(Mat m);
	void generate();
	Mat get();
};

#endif
