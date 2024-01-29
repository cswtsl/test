#include "mainform.h"
#include "ui_mainform.h"
#include<QLabel>
MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    cascade.load("D://opencv_3.4.2_Qt//etc//haarcascades//haarcascade_frontalface_default.xml");
    this->setFixedSize(this->width(),this->height());
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(socket,SIGNAL(readyRead()),this,SLOT(recv_data()));

    playthread = new PlayThread();
    camervideo = new CamerVideo();
    playthread->setCamerVideo(camervideo);
    connect(camervideo,SIGNAL(sendImage(QImage)),this,SLOT(recv_img(QImage)));

    runthread = new RunThread();
    car = new DeterCarMove("d://carMove.mp4");
    runthread->setCar(car);
    connect(car,SIGNAL(sendImage(QImage)),this,SLOT(recv_img1(QImage)));

    playthread2 = new PlayThread();
    camervideo2 = new CamerVideo("d://video//video2.wmv");
    playthread2->setCamerVideo(camervideo2);
    connect(camervideo2,SIGNAL(sendImage(QImage)),this,SLOT(recv_img2(QImage)));

    playthread3 = new PlayThread();
    camervideo3 = new CamerVideo("d://video//video3.wmv");
    playthread3->setCamerVideo(camervideo3);
    connect(camervideo3,SIGNAL(sendImage(QImage)),this,SLOT(recv_img3(QImage)));

    playthread4 = new PlayThread();
    camervideo4 = new CamerVideo("d://video//video4.wmv");
    playthread4->setCamerVideo(camervideo4);
    connect(camervideo4,SIGNAL(sendImage(QImage)),this,SLOT(recv_img4(QImage)));

    playthread5 = new PlayThread();
    camervideo5 = new CamerVideo("d://video//video5.wmv");
    playthread5->setCamerVideo(camervideo5);
    connect(camervideo5,SIGNAL(sendImage(QImage)),this,SLOT(recv_img5(QImage)));

    playthread6 = new PlayThread();
    camervideo6 = new CamerVideo("d://video//video6.wmv");
    playthread6->setCamerVideo(camervideo6);
    connect(camervideo6,SIGNAL(sendImage(QImage)),this,SLOT(recv_img6(QImage)));

    playthread7 = new PlayThread();
    camervideo7 = new CamerVideo("d://video//video7.wmv");
    playthread7->setCamerVideo(camervideo7);
    connect(camervideo7,SIGNAL(sendImage(QImage)),this,SLOT(recv_img7(QImage)));

    playthread8 = new PlayThread();
    camervideo8 = new CamerVideo("d://video//video8.wmv");
    playthread8->setCamerVideo(camervideo8);
    connect(camervideo8,SIGNAL(sendImage(QImage)),this,SLOT(recv_img8(QImage)));
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::on_pushButton_9_clicked()
{

}

void MainForm::recv_img(const QImage &img)
{
    ui->labVideo1->setPixmap(QPixmap::fromImage(img.scaled(ui->labVideo1->size(),Qt::KeepAspectRatio)));
    ui->labVideo1->setScaledContents(true);
}

void MainForm::recv_img1(const QImage &img)
{
    ui->labVideo2->setPixmap(QPixmap::fromImage(img.scaled(ui->labVideo2->size(),Qt::KeepAspectRatio)));
    ui->labVideo2->setScaledContents(true);
}

void MainForm::recv_img2(const QImage &img)
{
    ui->labVideo3->setPixmap(QPixmap::fromImage(img.scaled(ui->labVideo3->size(),Qt::KeepAspectRatio)));
    ui->labVideo3->setScaledContents(true);
}

void MainForm::recv_img3(const QImage &img)
{
    ui->labVideo4->setPixmap(QPixmap::fromImage(img.scaled(ui->labVideo4->size(),Qt::KeepAspectRatio)));
    ui->labVideo4->setScaledContents(true);
}

void MainForm::recv_img4(const QImage &img)
{
    ui->labVideo5->setPixmap(QPixmap::fromImage(img.scaled(ui->labVideo5->size(),Qt::KeepAspectRatio)));
    ui->labVideo5->setScaledContents(true);
}

void MainForm::recv_img5(const QImage &img)
{
    ui->labVideo6->setPixmap(QPixmap::fromImage(img.scaled(ui->labVideo6->size(),Qt::KeepAspectRatio)));
    ui->labVideo6->setScaledContents(true);
}

void MainForm::recv_img6(const QImage &img)
{
    ui->labVideo7->setPixmap(QPixmap::fromImage(img.scaled(ui->labVideo7->size(),Qt::KeepAspectRatio)));
    ui->labVideo7->setScaledContents(true);
}

void MainForm::recv_img7(const QImage &img)
{
    ui->labVideo8->setPixmap(QPixmap::fromImage(img.scaled(ui->labVideo8->size(),Qt::KeepAspectRatio)));
    ui->labVideo8->setScaledContents(true);
}

void MainForm::recv_img8(const QImage &img)
{
    ui->labVideo9->setPixmap(QPixmap::fromImage(img.scaled(ui->labVideo9->size(),Qt::KeepAspectRatio)));
    ui->labVideo9->setScaledContents(true);
}

void MainForm::recv_data()
{
    QString s=socket->readAll();
    ui->label_2->setText(s);
}

void MainForm::on_pushButton_4_clicked()
{
    playthread->start();
    runthread->start();
    playthread2->start();
    playthread3->start();
    playthread4->start();
    playthread5->start();
    playthread6->start();
    playthread7->start();
    playthread8->start();
}

void MainForm::on_btn_min_clicked()
{
    this->showMinimized();
}

void MainForm::on_btn_close_clicked()
{
    qApp->exit();//Qt应用程序退出
}

void MainForm::on_btn_max_clicked()
{
    this->showMaximized();
}

void MainForm::on_pushButton_6_clicked()
{
    ui->pushButton_6->setEnabled(false);
    camervideo->openFaceDetect();
    //car->openFaceDetect();
    camervideo2->openFaceDetect();
    camervideo3->openFaceDetect();
    camervideo4->openFaceDetect();
    camervideo5->openFaceDetect();
    camervideo6->openFaceDetect();
    camervideo7->openFaceDetect();
    camervideo8->openFaceDetect();
}

void MainForm::remove_layout()
{
    ui->hlayout1->removeWidget(ui->labVideo1);
    ui->hlayout1->removeWidget(ui->labVideo2);
    ui->hlayout1->removeWidget(ui->labVideo3);

    ui->labVideo1->setVisible(false);
    ui->labVideo2->setVisible(false);
    ui->labVideo3->setVisible(false);

    ui->hlayout2->removeWidget(ui->labVideo4);
    ui->hlayout2->removeWidget(ui->labVideo5);
    ui->hlayout2->removeWidget(ui->labVideo6);

    ui->labVideo4->setVisible(false);
    ui->labVideo5->setVisible(false);
    ui->labVideo6->setVisible(false);

    ui->hlayout3->removeWidget(ui->labVideo7);
    ui->hlayout3->removeWidget(ui->labVideo8);
    ui->hlayout3->removeWidget(ui->labVideo9);

    ui->labVideo7->setVisible(false);
    ui->labVideo8->setVisible(false);
    ui->labVideo9->setVisible(false);
}

void MainForm::on_setfourbtn_clicked()
{
    this->remove_layout();
    ui->hlayout1->addWidget(ui->labVideo1);
    ui->hlayout2->addWidget(ui->labVideo4);

    ui->labVideo4->setVisible(true);
    ui->labVideo1->setVisible(true);

    int w=ui->labVideo4->width();
    int h=ui->labVideo4->height();
    ui->labVideo1->resize(w,h);




    ui->hlayout1->addWidget(ui->labVideo2);
    ui->hlayout2->addWidget(ui->labVideo5);

    ui->labVideo5->setVisible(true);
    ui->labVideo2->setVisible(true);


}

void MainForm::on_setonebtn_clicked()
{
    remove_layout();
    ui->hlayout1->addWidget(ui->labVideo1);
    ui->labVideo1->setVisible(true);
}

void MainForm::on_setninebtn_clicked()
{
    remove_layout();
    ui->hlayout1->addWidget(ui->labVideo1);
    ui->hlayout1->addWidget(ui->labVideo2);
    ui->hlayout1->addWidget(ui->labVideo3);

    ui->labVideo1->setVisible(true);
    ui->labVideo2->setVisible(true);
    ui->labVideo3->setVisible(true);

    ui->hlayout2->addWidget(ui->labVideo4);
    ui->hlayout2->addWidget(ui->labVideo5);
    ui->hlayout2->addWidget(ui->labVideo6);

    ui->labVideo4->setVisible(true);
    ui->labVideo5->setVisible(true);
    ui->labVideo6->setVisible(true);

    ui->hlayout3->addWidget(ui->labVideo7);
    ui->hlayout3->addWidget(ui->labVideo8);
    ui->hlayout3->addWidget(ui->labVideo9);

    ui->labVideo7->setVisible(true);
    ui->labVideo8->setVisible(true);
    ui->labVideo9->setVisible(true);

    int w=ui->labVideo2->width();
    int h=ui->labVideo2->height();
    ui->labVideo1->resize(w,h);

}

void MainForm::on_pushButton_2_clicked()
{
    QString ip=ui->lineEdit->text();
    unsigned short port=6666;
    socket->connectToHost(ip,port);
    ui->label_2->setText("连接成功！");
    ui->pushButton_2->setEnabled(false);
}

void MainForm::on_pushButton_3_clicked()
{
    QString s = ui->lineEdit_2->text();
    ui->lineEdit_2->clear();
    socket->write(s.toUtf8());
}

void MainForm::on_pushButton_clicked()
{
    socket->close();
    ui->pushButton_2->setEnabled(true);
}

void MainForm::on_pushButton_5_clicked()
{
    car->openFaceDetect();
    ui->pushButton_5->setEnabled(false);
}
