#include <stdio.h>

unsigned int bitOn( unsigned int N )
{
	unsigned int numOf1s = 0;
	
	while ( N > 0 )
	{
		if ( (N & 0x01) )
			numOf1s++;
		
		N = N >> 1;
	}
	
	return numOf1s;
}

void main ()
{
	unsigned int num;
	
	printf ( "\n*********************************************************");
	printf ( "\n Input  = Positive Integer number ");
	printf ( "\n Output = If we convert the number to binary, how many 1's are present");
	printf ( "\n*********************************************************\n");
	printf ( "\nEnter a number - ");
	scanf  ( "%d", &num);
	
	printf ( "\nNumber of 1's present in %d is = %d\n\n\n", num, bitOn(num));
}