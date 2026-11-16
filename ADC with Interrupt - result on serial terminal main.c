#include "adc.h"
#include "UART.h"
#include <stdio.h>
void delay(unsigned int time)
{
unsigned int i,j;
for(i = 0; i < time; i++)
for(j = 0; j < 5000; j++);
}
int main()
{
ADC_init(0x06); // channels AD0.1 + AD0.2, interrupt mode
UartInit(9600); // UART0 at 9600 baud
while(1)
{
printf("AD0.1 = %4d \t", ADC_read(1)); // value saved by ADC interrupt
printf("AD0.2 = %4d\r\n", ADC_read(2));
delay(1000);
}
}
