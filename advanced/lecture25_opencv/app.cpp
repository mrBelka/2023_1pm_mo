#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

    // Create a VideoCapture object and open the input file
    // If the input is the web camera, pass 0 instead of the video file name
    VideoCapture cap(0);

    // Check if camera opened successfully
    if (!cap.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }

    while (1) {

        Mat frame;
        // Capture frame-by-frame
        cap >> frame;

        int width = frame.cols;
        int height = frame.rows;

        int minx = width;
        int maxx = 0;
        int miny = height;
        int maxy = 0;

        for (int i = 0; i<height; i++)
            for (int j = 0; j < width; j++)
            {
                Vec3b bgr = frame.at<Vec3b>(i, j);
                if (bgr[0] < 100 && bgr[1] > 130 && bgr[2] > 170)
                {
                    Vec3b color(0, 0, 0);
                    frame.at<Vec3b>(i, j) = color;

                    if (i > maxy)maxy = i;
                    if (i < miny)miny = i;
                    if (j > maxx)maxx = j;
                    if (j < minx)minx = j;
                }
            }

        Rect r = Rect(minx, miny, maxx-minx, maxy-miny);
        //create a Rect with top-left vertex at (10,20), of width 40 and height 60 pixels.
        rectangle(frame, r, Scalar(255, 0, 0), 1, 8, 0);
        //Vec3b bgr = frame.at<Vec3b>(height/2, width/2);
        //std::cout << (int)bgr[0] << " " << (int)bgr[1] << " " << (int)bgr[2] << std::endl;
        
        //std::cout << (int)bgrPixel[0] << std::endl;

        // If the frame is empty, break immediately
        if (frame.empty())
            break;

        // Display the resulting frame
        imshow("Frame", frame);

        // Press  ESC on keyboard to exit
        char c = (char)waitKey(25);
        if (c == 27)
            break;
    }

    // When everything done, release the video capture object
    cap.release();

    // Closes all the frames
    destroyAllWindows();

    return 0;
}