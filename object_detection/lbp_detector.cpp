/* Hands detector based on Local Binary Pattern descriptors
 * */

#include <opencv2/opencv.hpp>
#include <string>
#include "lbp.h"
#include <experimental/filesystem>

using namespace std;
using namespace cv;
namespace filesys = std::experimental::filesystem;

string get_file_name(string file_path) {
    int pos = file_path.rfind('/');
    return file_path.substr(pos  + 1);
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
    return 0;
}

