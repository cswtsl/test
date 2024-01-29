#include "runthread.h"

RunThread::RunThread()
{

}
void RunThread::setCar(DeterCarMove *v)
{
    this->car=v;
}

void RunThread::run()
{
    car->play();
}
