#include <stdio.h>

void print_binary(unsigned x)
{
    for (unsigned bit = 1u << sizeof(int)*8-1; bit != 0; bit >>= 1)
	putchar((x & bit) ? '1' : '0');
}

int main()
{
  print_binary(2);
  return 0;
}
