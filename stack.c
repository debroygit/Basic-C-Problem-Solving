#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE		10
#define	INIT		1
#define PUSH_OP		'1'
#define POP_OP		'2'
#define	SHOW_OP		'3'
#define	EXIT_OP		'4'

void purpose (int print)
{
	
	printf ( "\n********************************************************************************************************\n");
	
	// If print = INIT,
	if ( print == INIT )
		printf ( "Implement Integer Stack using dynamic array\n");

	printf ("Valid operations -\n\
		Press %c to Push\n\
		Press %c to Pop\n\
		Press %c to Show the full content of Stack\n\
		Press %c to Exit\n\
		All other operations are invalid\n", PUSH_OP, POP_OP, SHOW_OP, EXIT_OP);
	
	printf ( "********************************************************************************************************\n");	
}

void assumptions ( int maxSize )
{
	printf ( "\n1. All inputs must be given between 2147483647 and -2147483648\
			  \n2. Stack Overflow and empty will be shown\
			  \n3. Max size of the Stack is - %d", maxSize);
}

int push ( int *stack, int top )
{
	int number;
	
	/*
	// Scan each number 
	printf ("\nEnter the number = ");
	scanf (" %d", &number);
	*/
	
	// Random numbers
	// initialize random seed:
	srand (time(NULL));
	number = rand();	
	printf ( "\n  Push: %d", number );
		
	stack[top] = number;
	return (top+1);
}

int pop ( int *stack, int top )
{
	printf ( "\nDelete : %d", stack[top-1] );
	return (top-1);
}

void showStack ( int *stack, int maxSize, int top )
{
	int i;
	printf ( "\nStack - " );
	for ( i=maxSize-1; i>=0; i-- )
	{
		if ( i == top-1 || ( top == 0 && i == 0 ))
			printf ( "\n  top-->");
		else
			printf ( "\n        ");
		
		if ( i < top )
			printf ( "[%12d  ]", stack[i]);
		else
			printf ( "[              ]");
	}
	
	printf ("\n");	
}

void main ()
{
	char	choice;
	int		*stack;
	int		maxSize;
	int		top=0;	//Top has the information of first free location
	int		operation=1;
	
	printf 	( "\nEnter the size of the Stack = ");
	scanf 	( " %d", &maxSize );
	
	assumptions ( maxSize );
	
	stack = (int *) malloc ( maxSize * sizeof (int) );
	
	while ( choice != EXIT_OP )
	{
		purpose (operation++);
		scanf ( " %c", &choice );
		switch ( choice )
		{
			case '1':
				if ( top < maxSize )
				{
					top = push(stack, top);
				}
				else 
				{
					printf ( "\nStack is full!");
				}
				break;
			case '2':
				if ( top > 0 )
				{
					top = pop (stack, top);
				}
				else 
				{
					printf ( "\nStack is empty!");
				}
				break;
			case '3':
				showStack (stack, maxSize, top);
				break;
			case '4':
				break;
			default :
				printf ( "\nThis %c is an invalid operation !", choice );
				break;
		}
	}
	
	printf ("\nProgram Ends\n"); 
}