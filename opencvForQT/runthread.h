#ifndef RUNTHREAD_H
#define RUNTHREAD_H
#include<opencv2/opencv.hpp>
#include <QThread>
#include"detercarmove.h"
#include<QString>
class RunThread : public QThread
{
public:
    RunThread();
    void setCar(DeterCarMove *v);
    void run();
signals:

public slots:

private:
    DeterCarMove* car;
};

#endif // RUNTHREAD_H
