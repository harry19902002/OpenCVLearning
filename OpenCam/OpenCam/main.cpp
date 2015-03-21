#include <QCoreApplication>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CvCapture* capture;                          //实例化CvCapture结构体
    capture = cvCreateCameraCapture(0);          //初始化从摄像头中获取视频，参数为摄像头索引，可为-1
    assert(capture != NULL);                     //确定摄像头被打开

    IplImage* img;
    img = cvQueryFrame(capture);
    cvNamedWindow("Cam",1);
    while(1)
    {
        img = cvQueryFrame(capture);              //从摄像头或者文件中抓取并返回一帧
        cvShowImage("Cam",img);
        char c = cvWaitKey(10);
        if(c == 'b')    break;                    //按b退出程序
    }
    cvReleaseCapture(&capture);                   //释放
    cvDestroyWindow("Cam");
    return a.exec();
}
