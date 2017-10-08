/*
	Write a program that reads in N non-negative integers
	from the user (one at a time) and show the maximum and
	minimum value
*/

#include <stdio.h>

void main ()
{
	int n, i;
	unsigned int max=0, min=-1, num;
	printf ("\n How many numbers ? ");
	scanf ("%d", &n);
	
	printf ("\nEnter numbers - \n");
	for (i=0; i<n; i++)
	{
		scanf ("%d", &num);
		
		if (num > max)
			max = num;
		if (num < min)
			min = num;	
	}
	
	printf ("\n Max = %d, Min = %d \n", max, min);
}