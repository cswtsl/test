#include "widget.h"
#include <QApplication>
#include<mainform.h>

//信号和槽实现响应
//qt为窗口组件，比如按钮，文本框都预先设计了信号
//你只要捕获到这个信号，我们用类的方法去接受成为槽函数
//设计一个类，这个类能够是实现对视频的播放和人脸、车辆的自动识别
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    MainForm w;
    w.show();

    return a.exec();
}
