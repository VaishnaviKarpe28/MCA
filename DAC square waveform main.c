#include <reg51.h>
void delay_250us(void) // Timer 1, Mode 1
{
TMOD = 0x10; // Timer 1 in Mode 1 (16-bit)
TH1 = 0xFF; // 65536 - 230 = 65306 = FF1AH
TL1 = 0x1A;
TR1 = 1; // start Timer 1
while(TF1 == 0); // wait till overflow
TR1 = 0; // stop Timer 1
TF1 = 0; // clear overflow flag
}
void main(void)
{
while(1)
{
P1 = 0xFF; // HIGH (DAC maximum)
delay_250us();
P1 = 0x00; // LOW (DAC 0)
delay_250us();
}
}
