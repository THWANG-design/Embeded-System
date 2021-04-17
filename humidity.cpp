#include <wiringPi.h>
#include <stdio.h>
int main(void)
{
  wiringPiSetup() ;
  pinMode (29, INPUT) ;
  for(;;)
  {
    if(digitalRead(29) == 1) 
    {
        printf("Dry\n");
        delay(500);
    }
    else
    {
        printf("Humid\n");
        delay(500);
    }
  }
  return 0;
}
