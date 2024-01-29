#include "camervideo.h"

CamerVideo::CamerVideo(QObject *parent) : QObject(parent)
{
    cap.open(0);
    cascade.load("D://opencv_3.4.2_Qt//etc//haarcascades//haarcascade_frontalface_default.xml");
    video_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    video_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    activeFaceDetect=false;
}

CamerVideo::CamerVideo(char *videoPath)
{
    cap.open(videoPath);
    cascade.load("D://opencv_3.4.2_Qt//etc//haarcascades//haarcascade_frontalface_default.xml");
    video_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    video_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    activeFaceDetect=false;
}

void CamerVideo::play()
{
  //用while循环读取数据到MAT中 while(cap.read(video_img))
  while(cap.read(video_img))
  {
      if(this->activeFaceDetect==true)
      {
          this->classFileDected(cascade,video_img);
      }
      cvtColor(video_img,video_img,CV_BGR2RGB);
      QImage image(video_img.data,this->video_width,this->video_height,QImage::Format_RGB888);
      emit sendImage(image);
      Sleep(100);
  }

}

void CamerVideo::openFaceDetect()
{
    this->activeFaceDetect=true;
}

void CamerVideo::classFileDected(CascadeClassifier &cascade, Mat &pic)
{
    Mat gray;
    vector<Rect> object;
    Mat smallImage(cvRound(pic.rows/2),cvRound(pic.cols/2),CV_8UC1);
    cvtColor(pic,gray,CV_BGR2GRAY);
    cv::resize(gray,smallImage,smallImage.size());
    //图片缩小并转灰度之后，为了提高识别精度，我们实现直方图均质化
    equalizeHist(smallImage,smallImage);
    cascade.detectMultiScale(smallImage,object,1.1,3,0|CV_HAAR_SCALE_IMAGE,Size(30,30));
    int x,y,w,h;
    for(vector<Rect>::const_iterator it =object.begin();it!=object.end();it++)
    {
        x=it->x;
        y=it->y;
        w=it->width;
        h=it->height;
        rectangle(pic,Point(x*2,y*2),Point(x*2+w*2,y*2+h*2),Scalar(25,255,0),3);
    }
}
