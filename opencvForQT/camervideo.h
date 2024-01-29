#ifndef CAMERVIDEO_H
#define CAMERVIDEO_H
#include<opencv2/opencv.hpp>
#include <QObject>
#include<synchapi.h>
#include<QImage>
#include<iostream>
using namespace cv;
using namespace std;
class CamerVideo : public QObject
{
    Q_OBJECT
public:
    explicit CamerVideo(QObject *parent = nullptr);
    explicit CamerVideo(char *videoPath);
    void play();
    void openFaceDetect();
signals:
    void sendImage(const QImage &img);
public slots:
private:
    CascadeClassifier cascade;
    bool activeFaceDetect;
    int video_width;
    int video_height;
    VideoCapture cap;
    Mat video_img;
    void classFileDected(CascadeClassifier &cascade, Mat &pic);
};

#endif // CAMERVIDEO_H
