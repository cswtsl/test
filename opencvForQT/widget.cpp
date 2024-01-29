#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //QT中每个控件都用事先设定好的信号，timeout信号，这个信号时间到达的时候就会发送这个信号
    //我们需要把刚刚设定好的槽函数和timeout信号关联在一起
    //connect(&video_timer,SIGNAL(timeout()),this,SLOT(timer_fun()));
    cascade.load("D://opencv_3.4.2_Qt//etc//haarcascades//haarcascade_frontalface_default.xml");
    camerVideo = new CamerVideo();
    playthread = new PlayThread() ;
    playthread->setCamerVideo(camerVideo);
    connect(camerVideo,SIGNAL(sendImage(QImage)),this,SLOT(recv_img(QImage)));
    camerVideo1 = new CamerVideo("d://video5.wmv");
    playthread1 = new PlayThread();
    playthread1->setCamerVideo(camerVideo1);
    connect(camerVideo1,SIGNAL(sendImage(QImage)),this,SLOT(recv_img1(QImage)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    Mat pic = imread("d://pythonProject//image//1.png");
    //qt中需要将图片的颜色从bgr改为rgp
    cvtColor(pic,pic,CV_BGR2RGB);
    QImage qt_image=QImage(pic.data,pic.cols,pic.rows,QImage::Format_RGB888);
    ui->label_3->setPixmap(QPixmap::fromImage(qt_image));
    pic = imread("d://1.jpg");
    //qt中需要将图片的颜色从bgr改为rgp
    cvtColor(pic,pic,CV_BGR2RGB);
    qt_image=QImage(pic.data,pic.cols,pic.rows,QImage::Format_RGB888);
    ui->label_4->setPixmap(QPixmap::fromImage(qt_image.scaled(ui->label_4->size(),Qt::KeepAspectRatio)));
    //在上节课中使用死循环实现播放视频，但在QT中使用while会导致界面不响应
    //解决方案：1.使用定时器 2.使用线程

}

void Widget::timer_fun()
{
    videocap.read(video_img);
    classFileDected(cascade,video_img);
    cvtColor(video_img,video_img,CV_BGR2RGB);
    QImage image=QImage(video_img.data,video_img.cols,video_img.rows,QImage::Format_RGB888);
    ui->label_2->setPixmap(QPixmap::fromImage(image.scaled(ui->label->size(),Qt::KeepAspectRatio)));
    //ui->label->setPixmap(QPixmap::fromImage(image));
}

void Widget::on_pushButton_2_clicked()
{
    //videocap.open(0);
    //video_timer.start(33);//定时器启动之后，每隔33毫秒会产生一个timeOut信号
    //Qt实现线程
    playthread->start();
    playthread1->start();
}

void Widget::recv_img(const QImage &img)
{
    ui->label_4->setPixmap(QPixmap::fromImage(img.scaled(ui->label->size(),Qt::KeepAspectRatio)));
}

void Widget::recv_img1(const QImage &img)
{
    ui->label->setPixmap(QPixmap::fromImage(img.scaled(ui->label->size(),Qt::KeepAspectRatio)));
}

void Widget::classFileDected(CascadeClassifier &cascade, Mat &pic)
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
