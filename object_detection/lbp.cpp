/*
Local Binary Patterns
https://en.wikipedia.org/wiki/Local_binary_patterns
*/

#include "lbp.h"

LBP::LBP(Mat m) {
    image = m;
    result = Mat::zeros(Size(image.cols, image.rows), CV_8UC1);
}

void LBP::generate() {
    for(int i = 1; i < image.rows-1; i++){
        for(int j = 1; j < image.cols-1; j++) {
            uint8_t center = image.at<uchar>(i, j);
            uint8_t value = 0;
            if(center >= image.at<uchar>(i-1, j)){ // top
                value |= 1;
            }
            if(center >= image.at<uchar>(i-1, j-1)){ // top-left
                value |= (1 << 1);
            }
            if(center >= image.at<uchar>(i, j-1)){ // left
                value |= (1 << 2);
            }
            if(center >= image.at<uchar>(i+1, j-1)){ // bottom-left
                value |= (1 << 3);
            }
            if(center >= image.at<uchar>(i+1, j)){ // bottom
                value |= (1 << 4);
            }
            if(center >= image.at<uchar>(i+1, j+1)){ // bottom-right
                value |= (1 << 5);
            }
            if(center >= image.at<uchar>(i, j+1)){ // right
                value |= (1 << 6);
            }
            if(center >= image.at<uchar>(i-1, j+1)){ // top-right
                value |= (1 << 7);
            }
            result.at<uchar>(i, j) = value;
        }
    }
}

Mat LBP::get(){
    return result;
}
