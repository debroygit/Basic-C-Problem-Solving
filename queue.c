// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Macros
#define MAXSIZE		10
#define	INIT		1
#define ADD_OP		'1'
#define DEL_OP		'2'
#define	SHOW_OP		'3'
#define	EXIT_OP		'4'
#define DEBUG		printf ( "%s:%d", __FUNCTION__, __LINE__)

// User defined functions
void purpose (int print)
{
	
	printf ( "\n********************************************************************************************************\n");
	
	// If print = INIT,
	if ( print == INIT )
		printf ( "Implement Integer queue using dynamic array\n");

	printf ("Valid operations -\n\
		Press %c to Add\n\
		Press %c to Delete\n\
		Press %c to Show the full content of Queue\n\
		Press %c to Exit\n\
		All other operations are invalid\n", ADD_OP, DEL_OP, SHOW_OP, EXIT_OP);
	
	printf ( "********************************************************************************************************\n");	
}

void assumptions ( int maxSize )
{
	printf ( "\n1. All inputs must be given between 2147483647 and -2147483648\
			  \n2. Queue Overflow and empty will be shown\
			  \n3. Max size of the Queue is - %d", maxSize);
}

int add ( int *queue, int maxSize, int totalEle, int *rear )
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
	printf ( "\n  Add: %d", number );
		
	queue[*rear] = number;
	*rear = (*rear + 1) % maxSize;
	return (totalEle+1);
}

int delete ( int *queue, int maxSize, int totalEle, int *front )
{
	printf ( "\nDelete : %d", queue[*front] );
	*front = (*front + 1) % maxSize;
	return (totalEle-1);
}

void displayQueue(int *queue, int maxSize, int totalEle, int rear, int front)
{
    int i;
    printf("\n Display Queue - ");
	
	for (i=0; i<maxSize; i++)
	{
		printf ( "\n" );
		
		if ( front > rear )
		{
			if ( 0 <= i && i < rear )
				printf ( "        [%12d  ]", queue[i] );
			else if ( i == rear )
				printf ( "        [              ]<--Rear");
			else if ( i == front )
				printf ( "Front-->[%12d  ]", queue[i] );
			else if ( i>= front && i < maxSize )
				printf ( "        [%12d  ]", queue[i] );
			else
				printf ( "        [              ]");
		}
		else if ( front == rear )
		{
			// There could be two cases
			// 	1. Queue empty
			//	2. Queue full
			if ( totalEle == 0 )
			{
				if ( i == front )
					printf ( "Front-->[              ]<--Rear" );
				else
					printf ( "        [              ]");
			}
			else
			{
				if ( i == front )
					printf ( "Front-->[%12d  ]<--Rear", queue[i] );
				else
					printf ( "        [%12d  ]", queue[i] );
			}
		}
		else // front < rear
		{
			if ( i == front )
				printf ( "Front-->" );
			else
				printf ( "        " );
			
			
			if ( i < front )
				printf ( "[              ]");
			else if ( i >= rear )
				printf ( "[              ]");
			else
				printf ( "[%12d  ]", queue[i] );
			
			
			if ( i == rear )
				printf ( "<--Rear" );
		}
	}
}


// MAIN function
void main ()
{
	char	choice;
	int		*queue;
	int		maxSize;
	int		rear=0, front=0, totalEle=0;
	int		operation=1;
	
	printf 	( "\nEnter the size of the Queue = ");
	scanf 	( " %d", &maxSize );
	
	assumptions ( maxSize );
	
	queue = (int *) calloc ( maxSize, sizeof (int) );
	
	while ( choice != EXIT_OP )
	{
		purpose (operation++);
		scanf ( " %c", &choice );
		switch ( choice )
		{
			case ADD_OP:
				if ( totalEle < maxSize )
				{
					totalEle = add (queue, maxSize, totalEle, &rear);
				}
				else 
				{
					printf ( "\nQueue is full!");
				}
				break;
			case DEL_OP:
				if ( totalEle > 0 )
				{
					totalEle = delete (queue, maxSize, totalEle, &front);
				}
				else 
				{
					printf ( "\nQueue is empty!");
				}
				break;
			case SHOW_OP:
				//showQueue (queue, maxSize, totalEle, rear, front);
				displayQueue (queue, maxSize, totalEle, rear, front);
				break;
			case EXIT_OP:
				break;
			default :
				printf ( "\nThis %c is an invalid operation !", choice );
				break;
		}
		printf ( "\nRear - %d, Front - %d, Ele - %d", rear, front, totalEle);
	}
	
	printf ("\nProgram Ends\n"); 
}