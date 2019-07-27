/* Hands detector based on Local Binary Pattern descriptors
 * */

#include <opencv2/opencv.hpp>
#include <string>
#include "lbp.h"
#include "histogram.h"
#include "utilities.cpp"

using namespace std;
using namespace cv;

Mat threshold_image(Mat input, int thr1, int thr2){
    Mat result = Mat::zeros(Size(input.cols, input.rows), CV_8UC1);
    for(int i=0; i < input.rows; i++){
        for(int j=0; j < input.cols; j++ ){
            uint8_t value = input.at<uchar>(i,j);
            if(value > thr1 && value < thr2){
                result.at<uchar>(i,j) = value;
                //result[1].at<uchar>(i,j) = 255;
                //result[2].at<uchar>(i,j) = 255;

            }

        }
    }
    return result;
}

int main(int argc, char** argv) {
    if(argc < 2) {
        cout << "Missing arguments." << endl;
        cout << "Usage: ./a.out <image>" << endl;
        return 1;
    }
    // Input image
    string img_path = argv[1];
    string img_name = get_file_name(img_path);
    // Read Image
    Mat img = imread(img_path);
    Mat grey_img;
    cvtColor(img, grey_img, COLOR_BGR2GRAY);
    // User LBP detector
    LBP detector = LBP(grey_img);
    detector.generate();
    Mat result = detector.get();
    imwrite("../results/lbp_result_"+img_name, result);
    // Generate the histogram
    Histogram hist = Histogram(result);
    hist.generate();
    Mat histImage = hist.get();
    // Save histogram
    string hist_name = "../results/lbp_hist_" + img_name;
    imwrite(hist_name, histImage);
    // After visual analysis, threshold are 100 and 170.
    // Let's generate three images using the thresholds
    Mat th_img_1 = threshold_image(grey_img, 0, 100);
    Mat th_img_2 = threshold_image(grey_img, 100, 170);
    Mat th_img_3 = threshold_image(grey_img, 170, 255);
    imwrite("../results/lbp_th_1_"+img_name, th_img_1);
    imwrite("../results/lbp_th_2_"+img_name, th_img_2);
    imwrite("../results/lbp_th_3_"+img_name, th_img_3);
    return 0;
}

