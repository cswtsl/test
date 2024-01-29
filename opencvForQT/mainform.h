#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include<opencv2/opencv.hpp>
#include"playthread.h"
#include"camervideo.h"
#include"detercarmove.h"
#include"runthread.h"
#include<QTcpSocket>
#include<QString>
using namespace cv;
using namespace std;
namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();



private slots:
    void on_pushButton_9_clicked();
    void recv_img(const QImage &img);
    void recv_img1(const QImage &img);
    void recv_img2(const QImage &img);
    void recv_img3(const QImage &img);
    void recv_img4(const QImage &img);
    void recv_img5(const QImage &img);
    void recv_img6(const QImage &img);
    void recv_img7(const QImage &img);
    void recv_img8(const QImage &img);

    void recv_data();
    void on_pushButton_4_clicked();

    void on_btn_min_clicked();

    void on_btn_close_clicked();

    void on_btn_max_clicked();

    void on_pushButton_6_clicked();

    void on_setfourbtn_clicked();

    void on_setonebtn_clicked();

    void on_setninebtn_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    QTcpSocket *socket;
    Ui::MainForm *ui;
    VideoCapture cap;
    Mat video_img;
    CascadeClassifier cascade;
    PlayThread *playthread;
    CamerVideo *camervideo;
    PlayThread *playthread1;
    CamerVideo *camervideo1;
    CamerVideo *camervideo2;
    PlayThread *playthread2;
    CamerVideo *camervideo3;
    PlayThread *playthread3;
    CamerVideo *camervideo4;
    PlayThread *playthread4;
    CamerVideo *camervideo5;
    PlayThread *playthread5;
    CamerVideo *camervideo6;
    PlayThread *playthread6;
    CamerVideo *camervideo7;
    PlayThread *playthread7;
    CamerVideo *camervideo8;
    PlayThread *playthread8;
    DeterCarMove *car;
    RunThread *runthread;
    void remove_layout();
};

#endif // MAINFORM_H
