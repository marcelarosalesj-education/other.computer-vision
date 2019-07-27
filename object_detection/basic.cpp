#include <opencv2/opencv.hpp>
#include <string>
#include "histogram.h"
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
    // Generate the histogram
    Histogram hist = Histogram(grey_img);
    hist.generate();
    Mat histImage = hist.get();
    // Save histogram
    string hist_name = "../results/hist_" + img_name;
    imwrite(hist_name, histImage);
    // Save image
    string img_output = "../results/hist_grey_" + img_name;
    cout << "Saving output image to " << img_output << endl;
    imwrite(img_output, grey_img);

  return 0;
}

