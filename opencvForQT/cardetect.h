#ifndef CARDETECT_H
#define CARDETECT_H



#include <QObject>
#include<synchapi.h>
#include<QImage>
#include<iostream>
class CarDetect : public QObject
{
    Q_OBJECT
public:
    explicit CarDetect(QObject *parent = nullptr);
    explicit CarDetect(char *videoPath);
signals:

public slots:
private:
    bool activeCarDetect;
};

#endif // CARDETECT_H
