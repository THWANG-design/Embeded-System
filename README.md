# Real-time Embeded System
## <font color=#0099ff size=7 face="黑体"> Contents </font> 
- 1. Project Introduction
- 2. Equipment 
- 3. How it works
  -  Implementation principle
  -  Partial screenshot
- 4. The Final Code
- 5. Social media and contact us

## Projetct Introduction
A implementation of project to use Raspberry Pi to design an intelligent wheelchair. It can not only provide users with the current weather and temperature, and could also detect the ground humidity and obstacles and give users feedback. It ensures the safety of wheelchair users.Our software can also store personal information. We can also navigate and browse news, etc. in the software, we can add emergency contact information and automatically send help information in case of emergency


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
| Dht11 | 26 | 32 | 26|
#### Obstacles detecting:
We use GPIO.23 and GPIO.24 interfaces as two obstacle detecting sensors' input. When the wheelchair is blocked behind, these two sensors give input to the Pi and we read the reference to control the wheelchair to stop. If obstacles are detected, that information will be shown on the GUI. 
#### Wet ground detecting:
    The GPIO.26 is used to detect if the ground is wet or not. 
    When the sensor gets the wet signal, it sends that to the Pi and we command the wheelchair to stop through that signal. 
    If ground is detected as wet, that information will be shown on the GUI. 
    
    We have a dht11 sensor to show the temperature and humidity of the surroundings. 
    The data is shown on the GUI as integers. It reminds the user to wear suitable clothes outside. The GPIO.25 is user for dht11 sensor.

    Of course, to simulate the wheelchair, there're two buttons that are connected to GPIO.21 and GPIO.22.
    When we push the button, the wheelchair can be controlled to move forward and backward as if they were handled by user in the real world.
    
    Finally, the wheels are controlled using GPIO.1~6. There are 5 functions to control the wheelchair to step forward, backward, turn left, right and stop. 
    All GND and VCC inputs and wheel motors are connected to the expansion board.
#### Demo video.
*****
- We create a function to show the temperature and humidity detected by the sensor. At the same time, we create an interface to show information. And we also made the manual mode for the system. So the reversing aid part will not work if someone pushes the wheelchair.
    [Click here to temperature decting demo video](https://twitter.com/realtime_smart/status/1384018424637001734)
    
- The second part is to detect the wet ground. If there is water on the ground, it might be dangerous to the person who sits in the wheelchair. So we create this function.
    [Click here to Wet decting demo video](https://twitter.com/realtime_smart/status/1384016938376982529)
    
- The essential part is to build the infrared ranging reversing aid function. We use the infrared distance sensor to detect if there is any obstacle behind the wheelchair. If so, the wheelchair should be stopped by our system.
    [Click here to Wet decting demo video](https://twitter.com/realtime_smart/status/1384016074132258821)

    
[Click here to  decting demo video]

## The Final Code
[Click here to Final Code](https://github.com/THWANG-design/Embeded-System/tree/main/code) 
*****
#### Contact us
Taohan Wang 2520367w@student.gla.ac.uk
    Dongyu Wang 2536502W@student.gla.ac.uk
    Yuhao Xu    2577620X@student.gla.ac.uk

- [Face book](https://www.facebook.com/wheelchair.smart) 
- [ Twitter ](https://twitter.com/realtime_smart)
*****








