#include <wiringPi.h>
int main(void)
{
  wiringPiSetup() ;
  pinMode (21, OUTPUT);
  pinMode (23, INPUT);
  for(;;)
  {
    if(digitalRead(23) == 0) 
    {
    digitalWrite(21, HIGH) ; delay (500) ;
    digitalWrite(21,  LOW) ; delay (500) ;
    }
  }
}
