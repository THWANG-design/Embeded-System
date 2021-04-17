#include "widget.h"
#include "ui_widget.h"
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

typedef unsigned char uint8;
typedef unsigned int  uint16;
typedef unsigned long uint32;

#define HIGH_TIME 32

void  t_up(int speed, unsigned int t_time)
{
     digitalWrite(2,0);
     digitalWrite(3,1);
     softPwmWrite(1,speed);

     digitalWrite(5,0);
     digitalWrite(6,1);
     softPwmWrite(4,speed);
     delay(t_time);
}

void t_stop(unsigned int t_time)
{
     digitalWrite(2,0);
     digitalWrite(3,0);
     softPwmWrite(1,0);

     digitalWrite(5,0);
     digitalWrite(6,0);
     softPwmWrite(4,0);
     delay(t_time);
}

void t_down(int speed,unsigned int t_time)
{
     digitalWrite(2,1);
     digitalWrite(3,0);
     softPwmWrite(1,speed);

     digitalWrite(5,1);
     digitalWrite(6,0);
     softPwmWrite(4,speed);
     delay(t_time);
}

void t_left(int speed,unsigned int t_time)
{
     digitalWrite(2,1);
     digitalWrite(3,0);
     softPwmWrite(1,speed);

     digitalWrite(5,0);
     digitalWrite(6,1);
     softPwmWrite(4,speed);
     delay(t_time);
}

void t_right(int speed,unsigned int t_time)
{
     digitalWrite(2,0);
     digitalWrite(3,1);
     softPwmWrite(1,speed);

     digitalWrite(5,1);
     digitalWrite(6,0);
     softPwmWrite(4,speed);
     delay(t_time);
}

static int databuf;

uint8 readSensorData(void)
{
    int crc = 0;
    int i = 0;

    pinMode(7, OUTPUT); // set mode to output
    digitalWrite(7, 0); // output a high level
    delay(25);
    digitalWrite(7, 1); // output a low level
    pinMode(7, INPUT); // set mode to input
    pullUpDnControl(7, PUD_UP);

    delayMicroseconds(27);
    if (digitalRead(7) == 0) //SENSOR ANS
    {
        while (!digitalRead(7))
            ; //wait to high

        for (i = 0; i < 32; i++)
        {
            while (digitalRead(7))
                ; //data clock start
            while (!digitalRead(7))
                ; //data start
            delayMicroseconds(HIGH_TIME);
            databuf *= 2;
            if (digitalRead(7) == 1) //1
            {
                databuf++;
            }
        }

        for (i = 0; i < 8; i++)
        {
            while (digitalRead(7))
                ; //data clock start
            while (!digitalRead(7))
                ; //data start
            delayMicroseconds(HIGH_TIME);
            crc *= 2;
            if (digitalRead(7) == 1) //1
            {
                crc++;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, [=](){
        while(1){
        if((digitalRead(23)!=0)&&(digitalRead(24)!=0)){
            if(digitalRead(22)==0){
            t_down(15,500);
            t_stop(12);
            }
         }
        if(digitalRead(21)==0){
           t_up(15,500);
           t_stop(12);
         }
       }
    });
    ui->stackedWidget->setCurrentIndex(1);
    connect(ui->button1, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->button2, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
}

Widget::~Widget()
{
    delete ui;
}
