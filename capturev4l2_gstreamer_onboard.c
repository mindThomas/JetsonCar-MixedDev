//Build using g++ opencv.cpp `pkg-config --cflags --libs opencv`
#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char**)
{
    VideoCapture cap("nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)1280, height=(int)720, format=(string)I420, framerate=(fraction)24/1 ! nvvidconv flip-method=0 ! video/x-raw, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink"); // open the default camera
    if(!cap.isOpened())
        return -1;
    

    namedWindow("Preview",1);
    Mat frame;
    for(;;)
    {
        cap >> frame; // get a new frame from camera
        imshow("Preview", frame);
        if(waitKey(2) >= 0) break;
    }
    return 0;
}
