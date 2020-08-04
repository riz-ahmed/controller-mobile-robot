# controller-mobile-robot
In this project a controller is developed for a mobile robot, aiming towards autonomous driving. In the earlier steps a STM32 and TI micro-controllers are used for 
prototyping steering and propelling controls. A raspberry pi is planned to be used for image processing algorithms during later project developement.

Drivers for SPI, USART and I2C were added initially before implementing CAN as the main communication protocol between multiple sensors for steering, lean angle and forward velocity.

USART is mainly used for debugging, use the virtual terminal for checking the automated debug messages.

[21.04.2020] CAN drivers successfully tested on STM32

[15.05.2020] CAN drivers being developed for TI microcontroller to be used as a node as well
