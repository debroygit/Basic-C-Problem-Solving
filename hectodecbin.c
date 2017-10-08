// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Macros
#define MAXSIZE		8

// User defined functions
void purpose ()
{
	printf ( "\n********************************************************************************************************\n");
	printf ( "Convert a Hexadecimal number to Decimal and Binary\n");
	printf ( "********************************************************************************************************\n");	
}

void assumptions ( int maxSize )
{
	printf ( "\n1. Input should be a whole numbers\
			  \n2. Input should be always positive numbers\
			  \n3. Input must be in hexadecimal format (0-9, A-F, a-f)\
			  \n4. Hexadecimal number will have atmost %d digits\n\n", MAXSIZE);
}

void convert_to_binary ( unsigned int number )
{
	printf ( "\n  Binary  - ");
	while ( number > 0 )
	{
		printf ( "%d", number%2 );
		number /= 2;
	}
	
	printf ( "\n" );
}

unsigned int convert_to_decimal ( char *input, unsigned int size )
{
	unsigned int index;
	unsigned int decimal = 0;
	unsigned int power = 1;
	
	for (index=0; index<size; index++)
	{
		power *= 16;
	}
	
	for (index=0; index<size; index++)
	{
		power /= 16;
		switch ( input[index] )
		{
			case 'a':
			case 'A':
				decimal += 10 * power;
				break;
			case 'b':
			case 'B':
				decimal += 11 * power;
				break;			
			case 'c':
			case 'C':
				decimal += 12 * power;
				break;
			case 'd':
			case 'D':
				decimal += 13 * power;
				break;
			case 'e':
			case 'E':
				decimal += 14 * power;
				break;
			case 'f':
			case 'F':
				decimal += 15 * power;
				break;
			default :
				decimal += (input[index]-48) * power;
				break;
		}
		//printf ( "\n  Decimal - %u", decimal);
	}
	
	printf ( "\n  Decimal - %u", decimal);	
	return decimal;
}

void error_checking ( char *input, unsigned int size )
{
	unsigned int i;
	
	for ( i=0; i<size; i++)
	{
		if ( !((input[i] >= 48 && input[i] <= 57) ||	// 0 to 9
			   (input[i] >= 65 && input[i] <= 70) ||	// A to F
			   (input[i] >= 97 && input[i] <= 102)) )	// a to f
		{
			printf ( "\nIncorrect Input!");
			assumptions ( size );
			printf ( "\nTry again! \n");
			exit (1);
		}
	}
}

void conversion ()
{
	char *input, c;
	unsigned int i=0, size, equivalent_decimal=0;
	
	printf ( "\nEnter the size of hexadecimal number - ");
	scanf  ( " %d", &size );
	if ( size > MAXSIZE )
	{
		assumptions ( size );
		printf ( "\nTry again! \n");
		exit (1);
	}
	
	input = (char *) calloc (size, sizeof (char));
	
	printf ( "\nEnter the hexadecimal digits - ");
	
	while ( i < size )
	{
		scanf  ( " %c", &c);
		input[i++] = c;
	}
	
	error_checking ( input, size );
	equivalent_decimal = convert_to_decimal ( input, size );
	convert_to_binary ( equivalent_decimal );
}

void main ()
{
	purpose ();
	assumptions ( MAXSIZE );
	conversion();
	printf ("\nProgram Ends\n");
}