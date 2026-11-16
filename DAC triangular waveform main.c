#include <reg51.h>
void main(void)
{
unsigned char value;
while(1)
{
for(value = 0; value < 255; value++) // ramp UP : 0 to 254
P1 = value; // DAC0808 on Port 1
for(value = 255; value > 0; value--) // ramp DOWN : 255 to 1
P1 = value;
}
}
