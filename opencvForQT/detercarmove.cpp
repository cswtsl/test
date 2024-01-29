#include "detercarmove.h"

DeterCarMove::DeterCarMove(QObject *parent) : QObject(parent)
{

}

DeterCarMove::DeterCarMove(char *videoPath)
{
    cap.open(videoPath);
    video_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    video_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    activeFaceDetect=false;
}

void DeterCarMove::play()
{
    Mat video_img,tmp_img;
    Mat result_img;
    //CascadeClassifier cascade;
    //cascade.load("D://opencv_3.4.2_Qt//etc//haarcascades//haarcascade_frontalface_default.xml");
    int count=0;//统计帧数
    while(cap.read(video_img))
    {
        if(this->activeFaceDetect==1)
        {
            count++;
            if(count == 1)
            {
                result_img=CarDetect(video_img,video_img);
            }
            else
            {
                result_img=CarDetect(tmp_img,video_img);

            }
            tmp_img=video_img.clone();
        }
        else {
            result_img=video_img.clone();
        }
        cvtColor(result_img,result_img,CV_BGR2RGB);
        QImage image(result_img.data,this->video_width,this->video_height,QImage::Format_RGB888);
        emit sendImage(image);
        Sleep(100);
    }
}

void DeterCarMove::openFaceDetect()
{
    this->activeFaceDetect=true;
}

Mat DeterCarMove::CarDetect(Mat &frame1, Mat &frame2)
{
    Mat result = frame2.clone();
    //在进行车辆识别的时候，计算机识别图像中的物体的时候，为了提高识别效率，颜色对于物体识别并不重要，但颜色信息又占有大量数据
    //把颜色去掉提高运算速率
    Mat gray1,gray2;
    Mat diff;
    cvtColor(frame1,gray1,CV_BGR2GRAY);
    cvtColor(frame2,gray2,CV_BGR2GRAY);
    //spencv通过absdiff函数可以对两张图片差异化进行对比
    absdiff(gray1,gray2,diff);
    threshold(diff,diff,25,255,CV_THRESH_BINARY);
    //imshow("threshold",diff);
    //腐蚀函数,把一些白色小点处理掉,增强暗部降低亮度
    Mat element = getStructuringElement(MORPH_RECT,Size(3,3));
    erode(diff,diff,element);
    //还有些白色的部分去不掉，就把白色部分加强
    Mat element2=getStructuringElement(MORPH_RECT,Size(19,19));
    dilate(diff,diff,element2);
    vector<vector<Point>> contours;//数组的数组
    findContours(diff,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
    vector<vector<Point>> contours_poly(contours.size());
    vector<Rect> boundRect(contours.size());
    int x,y,w,h;
    for(int i=0;i<contours.size();i++)
    {
        approxPolyDP(Mat(contours[i]),contours_poly[i],3,true);
        boundRect[i]=boundingRect(Mat(contours_poly[i]));
        x=boundRect[i].x;
        y=boundRect[i].y;
        w=boundRect[i].width;
        h=boundRect[i].height;
        rectangle(result,Point(x,y),Point(x+w,y+h),Scalar(25,255,0),3);
    }
    return result;
}
