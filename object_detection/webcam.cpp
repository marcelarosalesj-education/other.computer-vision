#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

VideoCapture cap(1);

int main(int argc, char** argv)
{
    bool stop = false;
    Mat original_image = Mat(352, 288, CV_8UC3);
    if(!cap.isOpened()){
        cout << "Camera not opened" << endl;
        return -1;
    } else {
        while(stop==false) {
            char key = waitKey(5);
            switch (key) {
                case 27: stop = true; break;                            
            }
            cap >> original_image;
            imshow("webcam", original_image);
        }
    }
    return 0;
}

