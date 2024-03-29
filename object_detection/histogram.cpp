/*
Source: https://docs.opencv.org/2.4/doc/tutorials/imgproc/histograms/histogram_calculation/histogram_calculation.html
*/
#include "histogram.h"

Histogram::Histogram(Mat m){
	image = m;
}

void Histogram::generate() {
	Mat src, dst;
	src = image;
	
	/// Separate the image in 3 places ( B, G and R )
	vector<Mat> bgr_planes;
	split( src, bgr_planes );

	/// Establish the number of bins
	int histSize = 256;

	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 } ;
	const float* histRange = { range };

	bool uniform = true; bool accumulate = false;

	Mat b_hist, g_hist, r_hist;

	/// Compute the histograms:
	calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
	if(bgr_planes.size() == 3) {
		calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
		calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );
	}
	// Draw the histograms for B, G and R
	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound( (double) hist_w/histSize );

	Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

	/// Normalize the result to [ 0, histImage.rows ]
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
	if(bgr_planes.size() == 3) {
		normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
		normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
	}
    /*cout << b_hist.rows << endl;
    cout << b_hist.cols << endl;
    for(int i=0; i< b_hist.rows; i++){
        cout << b_hist.at<float>(0, i) << endl;
    }*/
	/// Draw for each channel
	for( int i = 1; i < histSize; i++ )
	{
	    line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
			     Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
			     Scalar( 255, 0, 0), 2, 8, 0  );
	    if(bgr_planes.size() == 3) {
                    line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                                     Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                                     Scalar( 0, 255, 0), 2, 8, 0  );
                    line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                                     Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                                     Scalar( 0, 0, 255), 2, 8, 0  );
	    }
	}
	hist = histImage;
}


Mat Histogram::get() {
	if(hist.empty()){
		cout << "empty" << endl;
	}
	return hist;
}
