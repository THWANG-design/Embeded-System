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

#define BUFSIZE 512

int PWMA = 1;
int AIN2 = 2;
int AIN1 = 3;

int PWMB = 4;
int BIN2 = 5;
int BIN1 = 6;

void  t_up(unsigned int speed,unsigned int t_time)
{
	 digitalWrite(AIN2,0);
	 digitalWrite(AIN1,1);
	 softPwmWrite(PWMA,speed);
	 
	 digitalWrite(BIN2,0);
	 digitalWrite(BIN1,1);
	 softPwmWrite(PWMB,speed);
	 delay(t_time);
}

void t_stop(unsigned int t_time)
{
	 digitalWrite(AIN2,0);
	 digitalWrite(AIN1,0);
	 softPwmWrite(PWMA,0);
	 
	 digitalWrite(BIN2,0);
	 digitalWrite(BIN1,0);
	 softPwmWrite(PWMB,0);
	 delay(t_time);	
}

void t_down(unsigned int speed,unsigned int t_time)
{
	 digitalWrite(AIN2,1);
	 digitalWrite(AIN1,0);
	 softPwmWrite(PWMA,speed);
	 
	 digitalWrite(BIN2,1);
	 digitalWrite(BIN1,0);
	 softPwmWrite(PWMB,speed);
	 delay(t_time);	
}

void t_left(unsigned int speed,unsigned int t_time)
{
	 digitalWrite(AIN2,1);
	 digitalWrite(AIN1,0);
	 softPwmWrite(PWMA,speed);
	 
	 digitalWrite(BIN2,0);
	 digitalWrite(BIN1,1);
	 softPwmWrite(PWMB,speed);
	 delay(t_time);	
}

void t_right(unsigned int speed,unsigned int t_time)
{
	 digitalWrite(AIN2,0);
	 digitalWrite(AIN1,1);
	 softPwmWrite(PWMA,speed);
	 
	 digitalWrite(BIN2,1);
	 digitalWrite(BIN1,0);
	 softPwmWrite(PWMB,speed);
	 delay(t_time);	
}

int main(int argc, char *argv[])
{
      /*RPI*/
    wiringPiSetup();
    
    /*WiringPi GPIO*/
    pinMode (1, OUTPUT);	//PWMA
    pinMode (2, OUTPUT);	//AIN2
    pinMode (3, OUTPUT);	//AIN1	
    pinMode (4, OUTPUT);	//PWMB
    pinMode (5, OUTPUT);	//BIN2
    pinMode (6, OUTPUT);        //BIN1

    pinMode (21, INPUT);
    pinMode (22, INPUT);
    pinMode (23, INPUT);
    pinMode (24, INPUT);
    pinMode (25, INPUT);
	
	/*PWM output*/
    softPwmCreate(PWMA,0,100);
    softPwmCreate(PWMB,0,100);  
    
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
   }
    
    //t_down(25,1000);
    //t_left(25,1000);
    //t_right(25,1000);
