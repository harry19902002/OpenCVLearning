#include <QCoreApplication>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void cartoonifyImage(Mat scrColor,Mat dst);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    VideoCapture camera;
    camera.open(0);
    assert(camera.isOpened());

    camera.set(CV_CAP_PROP_FRAME_WIDTH,640);
    camera.set(CV_CAP_PROP_FRAME_HEIGHT,480);

    while(1)
    {
        Mat cameraFrame;
//        camera >> cameraFrame;
        while(!camera.read(cameraFrame));
        Mat displayedFrame(cameraFrame.size(),CV_8UC3);

        //开启变换
        cartoonifyImage(cameraFrame, displayedFrame);
        namedWindow("Photo");
        imshow("Photo",displayedFrame);
        char key = waitKey(20);
        if(key == 27) break;
    }
    camera.release();
    destroyWindow("Photo");

    return a.exec();
}

void cartoonifyImage(Mat srcColor,Mat dst)
{
    Mat gray;
    cvtColor(srcColor,gray,CV_BGR2GRAY);
    const int MEDIAN_BLUE_FILTER_SIZE = 7;
    medianBlur(gray,gray,MEDIAN_BLUE_FILTER_SIZE);
    Mat edges;
    const int LAPLACIAN_FILTER_SIZE = 5;
    Laplacian(gray,edges,CV_8U,LAPLACIAN_FILTER_SIZE);
    Mat mask;
    const int EDGES_THRESHOLD = 80;
    threshold(edges,mask,EDGES_THRESHOLD,255,THRESH_BINARY_INV);

    srcColor.copyTo(dst,mask);

}
