#ifndef PLAYTHREAD_H
#define PLAYTHREAD_H
#include<opencv2/opencv.hpp>
#include <QThread>
#include"camervideo.h"
#include<QString>
class PlayThread : public QThread
{
public:
    PlayThread();
    void setCamerVideo(CamerVideo *v);
    void run();//要想创建一个线程，只要定义一个类作用QThread的子类，然后把想要的代码放到run（）里面，run里面就是线程代码
private:
    CamerVideo *camervideo;
};

#endif // PLAYTHREAD_H
