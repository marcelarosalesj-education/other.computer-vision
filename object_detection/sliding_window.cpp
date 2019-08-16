/*
*/
#include "sliding_window.h"

SlidingWindow::SlidingWindow(Mat m, int wr, int wc){
    image = m;
    window_rows = wr;
    window_cols = wc;
}

Mat* SlidingWindow::get_candidates(){
    cout << "rows : " << window_rows << endl;
    cout << "cols : " << window_cols << endl;
    //
    for(int i=0; i<image.rows; i+=window_rows){
        for(int j=0; j<image.cols; j+=window_cols){
            Rect roi = Rect(j, i, window_cols, window_rows);
            Mat roi_img = image(roi);
            imwrite("roi_"+to_string(i)+"_"+to_string(j)+".jpg", roi_img);
        }
    }
    return &image;
}
