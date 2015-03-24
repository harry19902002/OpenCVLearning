#include <QCoreApplication>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    VideoCapture camera;                        //实例化VideoCapture对象
    camera.open(0);                             //初始化从摄像头中获取视频，参数为摄像头索引，可为-1
    assert(camera.isOpened());                  //确定摄像头被打开

    Mat img;
    cvNamedWindow("Cam",1);                     //打开窗口
    while(1)
    {
        while(!camera.read(img));               //等待图像显示，并从摄像头或者文件中抓取并返回一帧
        imshow("Cam",img);                      //显示图像
        char c = cvWaitKey(30);
        if(c == 'q')    break;                  //按q退出程序
    }
    camera.release();
    cvDestroyWindow("Cam");                     //关闭窗口
    return a.exec();
}
