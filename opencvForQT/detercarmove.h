#ifndef DETERCARMOVE_H
#define DETERCARMOVE_H

#include<opencv2/opencv.hpp>
#include <QObject>
#include<synchapi.h>
#include<QImage>
#include<iostream>
using namespace cv;
using namespace std;
class DeterCarMove : public QObject
{
    Q_OBJECT
public:
    explicit DeterCarMove(QObject *parent = nullptr);
    explicit DeterCarMove(char *videoPath);
    void play();
    void openFaceDetect();
signals:
    void sendImage(const QImage &img);
public slots:
private:
    bool activeFaceDetect;
    int video_width;
    int video_height;
    VideoCapture cap;
    Mat video_img;
    Mat CarDetect(Mat &frame1,Mat &frame2);
};

#endif // DETERCARMOVE_H
