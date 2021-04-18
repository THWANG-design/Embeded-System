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

int readSensorData(void)
{
    int crc = 0;
    int i = 0;

    pinMode(25, OUTPUT); // set mode to output
    digitalWrite(25, 0); // output a high level
    delay(25);
    digitalWrite(25, 1); // output a low level
    pinMode(25, INPUT); // set mode to input
    pullUpDnControl(25, PUD_UP);

    delayMicroseconds(27);
    if (digitalRead(25) == 0) //SENSOR ANS
    {
        while (!digitalRead(25))
            ; //wait to high

        for (i = 0; i < 32; i++)
        {
            while (digitalRead(25))
                ; //data clock start
            while (!digitalRead(25))
                ; //data start
            delayMicroseconds(HIGH_TIME);
            databuf *= 2;
            if (digitalRead(25) == 1) //1
            {
                databuf++;
            }
        }

        for (i = 0; i < 8; i++)
        {
            while (digitalRead(25))
                ; //data clock start
            while (!digitalRead(25))
                ; //data start
            delayMicroseconds(HIGH_TIME);
            crc *= 2;
            if (digitalRead(25) == 1) //1
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

void Widget::timerUpdate1(void){
        ui->label_9->setText("No");
        ui->label_10->setText("No");
        digitalWrite(25, 1); // output a high level
        if (readSensorData() == 1)
        {
            printf("Sensor data read ok!\n");
            ui->label_8->setNum(((databuf >> 24) & 0xff));
            ui->label_12->setNum(((databuf >> 24) & 0xff));
            ui->label_7->setNum((databuf >> 8) & 0xff);
            ui->label_11->setNum((databuf >> 8) & 0xff);
            printf("RH:%d.%d\n", (databuf >> 24) & 0xff, (databuf >> 16) & 0xff);
            printf("TMP:%d.%d\n", (databuf >> 8) & 0xff, databuf & 0xff);
            databuf = 0;
        }
        else
        {
            //printf("Sensor dosent ans!\n");
            //databuf = 0;
        }

       if(((digitalRead(23)!=0)&&(digitalRead(24)!=0))&&(digitalRead(26)==1)){
          if(digitalRead(22)==0){
             t_down(30,800);
             t_stop(12);
            }
        }else if ((digitalRead(23)==0)||(digitalRead(24)==0)) {
            ui->label_9->setText("Yes");
        }else if (digitalRead(26)!=1) {
            ui->label_10->setText("Yes");
        }
       if(digitalRead(21)==0){
         t_up(30,800);
         t_stop(12);
        }
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate1()));
    timer->start(50);
    setbuf(stdout, NULL);
           fflush(stdout);
    /*connect(ui->pushButton, &QPushButton::clicked, [=](){
    });*/
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
