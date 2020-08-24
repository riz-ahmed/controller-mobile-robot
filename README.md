# controller-mobile-robot
In this project a controller is developed for a mobile robot, aiming towards autonomous driving. In the earlier steps a STM32 and TI micro-controllers are used for 
prototyping steering and propelling controls. A raspberry pi is planned to be used for image processing algorithms during later project developement.

Drivers for SPI, USART and I2C were added initially before implementing CAN as the main communication protocol between multiple sensors for steering, lean angle and forward velocity.

USART is mainly used for debugging, use the virtual terminal for checking the automated debug messages.

<h2>Application developed on STM32 using HAL layer</h2>
<ul>
  <li>Application to configure PLL clock settings</li>
  <li>Added voltage regulator API to enable higher clock speeds</li>
  <li>Applcations deveioped for TIMER peripherals in Synchronous and Interrupt modes</li>
  <li>Application for PWM peripherals, working LED's --> needs to be expanded to servo motors</li>
  <li>Application developed for CAN peripheral both in Synchronous and Interrupt modes</li>
</ul>
