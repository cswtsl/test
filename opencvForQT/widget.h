#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<opencv2/opencv.hpp>
#include<QTimer>
#include"camervideo.h"
#include"playthread.h"
using namespace cv ;
using namespace std;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void timer_fun();

    void on_pushButton_2_clicked();

    void recv_img(const QImage &img);

    void recv_img1(const QImage &img);

private:
    Ui::Widget *ui;
    QTimer video_timer;
    VideoCapture videocap;
    Mat video_img;
    CascadeClassifier cascade;
    void classFileDected(CascadeClassifier &cascade,Mat &pic);
    CamerVideo *camerVideo;
    PlayThread *playthread;
    CamerVideo *camerVideo1;
    PlayThread *playthread1;

};

#endif // WIDGET_H
