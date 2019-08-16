#ifndef SLIDINGWINDOW_H
#define SLIDINGWINDOW_H

#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <string>

using namespace std;
using namespace cv;

class SlidingWindow {
	private:
	Mat image;
	Mat* candidates;
    int window_rows;
    int window_cols;
    public:
	SlidingWindow(Mat m, int wr, int wc);
	Mat* get_candidates();
};

#endif
