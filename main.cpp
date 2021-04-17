#include "widget.h"
#include <QApplication>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <time.h>
#include <arpa/inet.h>

#include <wiringPi.h>
#include <softPwm.h>





int main(int argc, char *argv[])
{


    wiringPiSetup();

    pinMode (1, OUTPUT);
    pinMode (2, OUTPUT);
    pinMode (3, OUTPUT);
    pinMode (4, OUTPUT);
    pinMode (5, OUTPUT);
    pinMode (6, OUTPUT);
    pinMode (7, OUTPUT);

    pinMode (21, INPUT);
    pinMode (22, INPUT);
    pinMode (23, INPUT);
    pinMode (24, INPUT);
    pinMode (25, INPUT);

    softPwmCreate(1,0,100);
    softPwmCreate(4,0,100);

    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
