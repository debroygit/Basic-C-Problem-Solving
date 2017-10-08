#include <stdio.h>
#include <stdlib.h>

void print_error ( int num1, int num2 )
{
	if ( num1 < 0 || num2 < 0 )
	{
		printf ( "\nAll numbers must be positive!\n");
		exit (1);
	}
}

/*
Algorithm is taken from 
https://en.wikipedia.org/wiki/Primality_test

Pseudocode function is_prime(n)
    if n == 1
        return false
    else if n == 3
        return true
    else if n mod 2 == 0 or n mod 3 == 0
        return false
    let i = 5
    while i * i <= n
        if n mod i == 0 or n mod (i + 2) == 0
            return false
        i = i + 6
    return true

*/

void prime_check ( int number )
{
	int i = 5;
	int is_prime = 0;
	
	if ( number <= 3 )
	{
		printf ( "%d ", number );
		return;
	}
	
	if ( number % 2 != 0 && number % 3 != 0 )
	{
		while ( (i * i) <= number )
		{
			if ( (number % i == 0) || (number % (i+2) == 0) )
				is_prime++;
			
			i += 6;	// i = i + 6
		}
		
		if ( is_prime == 0 )
			printf ( "%d ", number );
	}
}

void print_prime_numbers(int n1, int n2)
{
	int i, j;
	for ( i=n1; i<n2; i++)
	{
		prime_check ( i );
	}
}

void main ()
{
	int num1, num2;
	
	printf ( "\nProgram Starts\n" );
	printf ( "\n*********************************************************");
	printf ( "\n Input  = Two Positive Integer numbers ");
	printf ( "\n Output = Prime numbers between these two numbers");
	printf ( "\n*********************************************************\n");
	printf ( "\nEnter a range- ");
	scanf  ( "%d%d", &num1, &num2);
	
	print_error ( num1, num2 );
	
	if ( num1 > num2 )
		print_prime_numbers(num2, num1);
	else
		print_prime_numbers(num1, num2);
	
	printf ( "\nProgram Ends\n" );
}