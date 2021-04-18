# Real-time Embeded System
## <font color=#0099ff size=7 face="黑体"> Contents </font> 
- 1. Project Introduction
- 2. Equipment 
- 3. How it works
  -  Implementation principle
  -  Partial screenshot
- 4. The Final Code
- 5. Social media and git-hub Link
- 6. References

## Projetct Introduction
A implementation of project to use Raspberry Pi to design an intelligent wheelchair. It can not only provide users with the current weather and temperature, and could also detect the ground humidity and obstacles and give users feedback. It ensures the safety of wheelchair users.


## Equipment
Raspberry Pi 4B
QT 5.13
C++ language

## How it works
*****
| Function | GPIO | BOARD | wiringPi |
| ---------------- | ----- | -----| -----|
| Go forward | 21 | 29 | 21 |
| Go backward | 22 | 31 | 22 |
| Obstacle detecting | 23 | 33 | 23 |
| Obstacle detecting | 24 | 35 | 24 |
| Ground detecting | 25 | 37 | 25 |
| Dht11 | 26 |  | 32 | 26 | 26|





