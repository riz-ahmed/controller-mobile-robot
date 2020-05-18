/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>

#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "Task.h"
			
TaskHandle_t  xTask1_handle = NULL;
TaskHandle_t  xTask2_handle = NULL;

char usr_msg[250];

// Task -1 and Task - 2 function prototypes
void vTask1_handler (void *params);
void vTask2_handler (void *params);

static void prvSetupHardware(void);
static void prvSetupUart(void);
void printmsg(char *msg);

#define Available 			1
#define Not_Available 		0

uint8_t USART_Access_Key = Available;

#ifdef UseSemiHosting
// used for semihosting
extern void initialise_monitor_handles();
#endif

int main(void)
{
#ifdef UseSemiHosting
	// for semihosting
	initialise_monitor_handles();
#endif

	// 1. Deinitialize SystemCoreClock settings (default) of FreeRTOS to make the sysclock run at 16MHz
	RCC_DeInit();

	SystemCoreClockUpdate();

	// Initialise USART2 peripheral
	prvSetupHardware();


	sprintf(usr_msg,"This is hello-world application starting\r\n");
	printmsg(usr_msg);

	// Create Task - 1
	xTaskCreate(vTask1_handler, "Task - 1", configMINIMAL_STACK_SIZE, NULL, 2, &xTask1_handle);

	// Create Task - 2
	xTaskCreate(vTask2_handler, "Task - 2", configMINIMAL_STACK_SIZE, NULL, 2, &xTask2_handle);

	// FreeRTOS will put the tasks to ready state once created, from here the tasks at ready state needs to be picked up
	// by the scheduler

	// Starting the Scheduler
	vTaskStartScheduler();

	for(;;);
}

// Create Task -1 function
void vTask1_handler (void *params){
	while(1){
		if(USART_Access_Key == Available){
			USART_Access_Key = Not_Available;
			sprintf(usr_msg,"Executing Task - 1\r\n");
			printmsg(usr_msg);
			USART_Access_Key = Available;
			taskYIELD();
		}

	}
}

// Create Task -2 function
void vTask2_handler (void *params){
	while(1){
		if(USART_Access_Key == Available){
			USART_Access_Key = Not_Available;
			sprintf(usr_msg,"Executing Task - 2\r\n");
			printmsg(usr_msg);
			USART_Access_Key = Available;
			taskYIELD();
		}
	}
}

static void prvSetupUart(void)
{
	GPIO_InitTypeDef gpio_uart_pins;
	USART_InitTypeDef uart2_init;

	//1. Enable the UART2  and GPIOA Peripheral clock
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);

	//PA2 is UART2_TX, PA3 is UART2_RX

	//2. Alternate function configuration of MCU pins to behave as UART2 TX and RX

	//zeroing each and every member element of the structure
	memset(&gpio_uart_pins,0,sizeof(gpio_uart_pins));

	gpio_uart_pins.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	gpio_uart_pins.GPIO_Mode = GPIO_Mode_AF;
	gpio_uart_pins.GPIO_PuPd = GPIO_PuPd_UP;
	gpio_uart_pins.GPIO_OType= GPIO_OType_PP;
	gpio_uart_pins.GPIO_Speed = GPIO_High_Speed;
	GPIO_Init(GPIOA, &gpio_uart_pins);


	//3. AF mode settings for the pins
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2); //PA2
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2); //PA3

	//4. UART parameter initializations
	//zeroing each and every member element of the structure
	memset(&uart2_init,0,sizeof(uart2_init));

	uart2_init.USART_BaudRate = 115200;
	uart2_init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	uart2_init.USART_Mode =  USART_Mode_Tx | USART_Mode_Rx;
	uart2_init.USART_Parity = USART_Parity_No;
	uart2_init.USART_StopBits = USART_StopBits_1;
	uart2_init.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART2,&uart2_init);


	//5. Enable the UART2 peripheral
	USART_Cmd(USART2,ENABLE);

}

static void prvSetupHardware(void)
{
	//setup UART2
	prvSetupUart();
}

void printmsg(char *msg)
{
	for(uint32_t i=0; i < strlen(msg); i++)
	{
		while ( USART_GetFlagStatus(USART2,USART_FLAG_TXE) != SET);
		USART_SendData(USART2,msg[i]);
	}

	while ( USART_GetFlagStatus(USART2,USART_FLAG_TC) != SET);

}
