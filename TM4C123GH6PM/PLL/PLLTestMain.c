// PLLTestMain.c
// Runs on LM4F120/TM4C123
// Test the PLL function to verify that the system clock is
// running at the expected rate.  Use the debugger if possible
// or an oscilloscope connected to PF2.
// The #define statement in the file PLL.h allows PLL_Init() to
// initialize the PLL to the desired frequency.  When using an
// oscilloscope to look at LED1, it should be clear to see that
// the LED flashes about 2 (80/40) times faster with a 80 MHz 
// clock than with a 40 MHz clock.

#include "PLL.h"

#define GPIO_PORTF2             (*((volatile unsigned long *)0x40025010))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGC2_GPIOF      0x00000020  // port F Clock Gating Control

// delay function for testing from sysctl.c
// which delays 3*ulCount cycles
#ifdef __TI_COMPILER_VERSION__
	//Code Composer Studio Code
	void Delay(unsigned long ulCount){
	__asm (	"    subs    r0, #1\n"
			"    bne     Delay\n"
			"    bx      lr\n");
}

#else
	//Keil uVision Code
	__asm void
	Delay(unsigned long ulCount)
	{
    subs    r0, #1
    bne     Delay
    bx      lr
	}

#endif
int main(void){  volatile unsigned long delay;
  PLL_Init();
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; // activate port F
  delay = SYSCTL_RCGC2_R;      // allow time for clock to stabilize
  GPIO_PORTF_DIR_R |= 0x04;    // make PF2 out (PF2 built-in LED)
  GPIO_PORTF_AFSEL_R &= ~0x04; // regular port function
  GPIO_PORTF_DEN_R |= 0x04;    // enable digital I/O on PF2
                               // configure PF4 as GPIO
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFF0FFFF)+0x00000000;
  GPIO_PORTF_AMSEL_R = 0;      // disable analog functionality on PF
  while(1){
    GPIO_PORTF2 = 0x04;        // turn on LED1 (blue)
    Delay(13333333);           // delay ~0.5 sec at 80 MHz
    GPIO_PORTF2 = 0x00;        // turn off LED1 (blue)
    Delay(13333333);           // delay ~0.5 sec at 80 MHz
  }
}
