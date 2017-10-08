#include <stdio.h>


void printchristmastree(unsigned int num)
{
	int id1, id2;
	
	// Draw the '*'
	for ( id1=0; id1<=num; id1++)
	{
		for ( id2=0; id2<num-id1; id2++)
		{
			printf ( " " );
		}
		
		for ( id2=0; id2<id1; id2++)
		{
			printf ( "* " );
		}		
		printf ( "\n" );
	}
	
	// Draw "_||_"
	for ( id2=0; id2<num-3; id2++)
		printf ( " " );

	printf ( "_| |_\n\n" );
	
}

void main ()
{
	unsigned int num;
	
	printf ( "\n*********************************************************");
	printf ( "\n Input  = Positive Integer number ");
	printf ( "\n Output = Draw a christmas tree");
	printf ( "\n*********************************************************\n");
	printf ( "\nEnter a number - ");
	scanf  ( "%d", &num);
	
	printchristmastree(num);
}