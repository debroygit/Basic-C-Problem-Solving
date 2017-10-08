#include <stdio.h>
#include <stdlib.h>

unsigned int power2( unsigned int N )
{
	unsigned int pof2 = 1;
	int diff;
	if ( N == 0 ) 
	{
		printf ( "\nNumber must be greater than zero !\n");
		exit (0);
	}
	else if ( N == 1 ) 
	{
		return pof2;
	}
	else // At least 2 or more
	{
		do
		{
			pof2 *= 2;
			N = N/2;
		}while ( N > 1 );
		diff = (N-pof2) - (pof2*2-N);
		
		if (diff > 0) // (N-pof2) > (pof2*2-N)
			return pof2*2;
		else //(N-pof2) > (pof2*2-N) or (N-pof2) = (pof2*2-N)
			return pof2;
	}
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
	
	printf ( "\nNearest 2's power of %d is = %d\n\n\n", num, power2(num));
}