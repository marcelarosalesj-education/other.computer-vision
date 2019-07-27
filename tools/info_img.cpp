/*
 * Resources:
 * For Mat type:
 * https://stackoverflow.com/questions/10167534/how-to-find-out-what-type-of-a-mat-object-is-with-mattype-in-opencv
 * */
#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

string type2str(int type) {
  string r;

  uchar depth = type & CV_MAT_DEPTH_MASK;
  uchar chans = 1 + (type >> CV_CN_SHIFT);

  switch ( depth ) {
    case CV_8U:  r = "8U"; break;
    case CV_8S:  r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default:     r = "User"; break;
  }

  r += "C";
  r += (chans+'0');

  return r;
}

int main(int argc, char** argv) {
    if(argc >= 2) {
        Mat image = imread(argv[1]);
        
        string ty =  type2str( image.type() );
        printf("Matrix: %s %dx%d \n", ty.c_str(), image.cols, image.rows );
        
    }
    return 0;
}

