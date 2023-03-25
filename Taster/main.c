#include <stdio.h>

int main()
{
  *((volatile unsigned char*) 0x24) |= 0b00100000;

  while(1)
  {
    if((*((volatile unsigned char*) 0x23) & 0b00000001) == 0b00000001)
    {
      *((volatile unsigned char*) 0x25) |= 0b00100000;
    }
    else
    {
      *((volatile unsigned char*) 0x25) &= 0b00000000;
    }
  }

  return 0;
}