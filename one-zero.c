#include <stdio.h>

int main ()
{
	int x = 0x7FFFFFFF + 1;
	printf ( "\n%x = %d = %d\n", x, x, x-1);
	return 0;
}