# controller-mobile-robot
In this project a controller is developed for a mobile robot, aiming towards autonomous driving. In the earlier steps a STM32 and TI micro-controllers are used for 
prototyping steering and propelling controls. A raspberry pi is planned to be used for image processing algorithms during later project developement.

Drivers for SPI, USART and I2C were added initially before implementing CAN as the main communication protocol between multiple sensors for steering, lean angle and forward velocity.

USART is mainly used for debugging, use the virtual terminal for checking the automated debug messages.

# Applications developed on STM32 using HAL layer

* Application to configure PLL clock settings
* Added voltage regulator API to enable higher clock speeds
* Applcations deveioped for TIMER peripherals in Synchronous and Interrupt modes
* Application for PWM peripherals, working LED's --> needs to be expanded to servo motors
* Application developed for CAN peripheral both in Synchronous and Interrupt modes

# Applications developed on TM4CGH6PM micro-controller

* Application to configure PLL clock settings
* Application for PWM peripherals, for DC stepper motors
* Application developed for DC motor controller for robotics applications
* Application developed for Line Tracker, Wall Follower using Moore's Enginer
