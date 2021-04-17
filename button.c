#include <stdio.h>
        #include <stdlib.h>
        #include <wiringPi.h>
        #define KEY      21    //wiringPi模式第1号脚
        int main()
        {
          if(wiringPiSetup()==-1)
          {
            perror("树莓派启动失败");
           exit(-1);
         }
         pinMode(KEY,INPUT);//设置按键为输入
         //判断是否按下
         while(1){
           if(digitalRead(KEY)==0){//按下低电平，松手高电平
              puts("1");
           }
           if(digitalRead(22)==0){//按下低电平，松手高电平
              puts("0");
           }
         }
         return 0;
       }
