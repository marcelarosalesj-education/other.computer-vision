#include <opencv2/opencv.hpp>
#include <string>
#include "sliding_window.h"
#include "utilities.cpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
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
    // Get candidates
    SlidingWindow sw = SlidingWindow(grey_img, 54, 96); //108, 192
    Mat *res = sw.get_candidates();

    cout << "End." << endl;
    return 0;
}

