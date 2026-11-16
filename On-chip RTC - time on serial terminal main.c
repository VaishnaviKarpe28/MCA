#include"lpc214x.h"
#include<stdio.h>
extern void UartInit(unsigned int); // defined in UART.c
void delay(unsigned int time)
{
unsigned int i,j;
for(i = 0; i < time; i++)
for(j = 0; j < 5000; j++);
}
void RTCInit(void)
{
CIIR = 0x00; // no RTC interrupt
PREINT = 0x1C8; // PCLK = 15 MHz : (15000000 / 32768) - 1 = 456
PREFRAC = 0x61C0; // PCLK = 15 MHz : 15000000 - (457 x 32768) = 25024
CCR = 0x02; // reset clock counters
}
void SetTime(int hours, int mins, int sec)
{
SEC = sec; // set seconds
MIN = mins; // set minutes
HOUR = hours; // set hours
CCR = 0x01; // start the clock
}
int main(void)
{
UartInit(9600); // UART0 at 9600 baud
RTCInit();
SetTime(5,30,1); // 05:30:01
while(1)
{
printf("\nThe Time is %02d:%02d:%02d", (int)HOUR, (int)MIN, (int)SEC);
delay(500);
}
}
