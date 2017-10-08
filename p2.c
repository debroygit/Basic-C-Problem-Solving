/*
	Write a program which will not stop taking input
	until user gives 274877906944 ( 2 to the power 38 )
*/

#include <stdio.h>

void main ()
{
	int n, i;
	long int num;
	printf ("\n Unless 274877906944 is given, program won't terminate !");
	
	while (1)
	{
		printf ("\nEnter numbers - \n");
		scanf ("%ld", &num);
		
		if ( num == 274877906944 )
		{
			printf ("\n Number matches ! Program terminated!\n");
			break;
		}
		else
		{
			printf ("\n Number doesn't matche ! \n");
			printf ("Expected - 274877906944 | Achieved - %ld\n", num);
		}
	}
}