#include <stdio.h>
#include <stdlib.h>

void purpose ()
{
	printf ( "\n********************************************************************************************************\n");
	printf ( "Print a line and \\t will be replaced by tab and \\n will be replaced by new line\n");
	printf ( "********************************************************************************************************\n");	
}

void printOutput (char *line, int size)
{
	int i;
	
	printf ( "\nPrint Output : \n");
	for (i=0; i<size; i++)
	{
		if ( line[i] == '\\')
		{
			if ( line[i+1] == 't') 
				printf ( "\t");
			else if ( line[i+1] == 'n') 
				printf ( "\n");
			else 
				printf ( "\\%c", line[i+1]);
			i++;
		}
		else
			printf ( "%c", line[i] );
	}
}

void myPrintf ()
{
	int size,i;
	char *line;
	printf ( "\nEnter the size of character present in your input line (Including space) - ");
	scanf  ("%d", &size);
	
	line = (char *) malloc (size * sizeof(char));
	
	printf ( "\nWrite your input line - \n");
	for ( i=0; i<=size; i++)
		scanf  ( "%c", &line[i] );
	
	printOutput (line, size);
}

void main ()
{
	purpose ();
	myPrintf ();
	printf ("\nProgram Ends\n"); 
}