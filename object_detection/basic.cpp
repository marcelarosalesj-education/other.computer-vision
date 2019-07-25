#include <opencv2/opencv.hpp>
#include <string>
#include "histogram.h"
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
  string img_dir = "../images/";
  string img_name = "hand.jpg";
  string img_input = img_dir + img_name; 
  // Read Image
  Mat img = imread(img_input);
  Mat grey_img;
  cvtColor(img, grey_img, COLOR_BGR2GRAY);
  // Generate the histogram
  Histogram hist = Histogram(img);
  Mat histImage = hist.generate();
  // Save histogram
  string hist_name = "../images/hist_" + img_name;
  imwrite(hist_name, histImage);
  // Save image
  string img_output("../images/result_hand.jpg");
  cout << "Saving output image to " << img_output << endl;
  imwrite(img_output, grey_img);

  return 0;
}

