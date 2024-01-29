#include "playthread.h"

PlayThread::PlayThread()
{

}

void PlayThread::setCamerVideo(CamerVideo *v)
{
    this->camervideo=v;
}

void PlayThread::run()
{
    this->camervideo->play();
}
