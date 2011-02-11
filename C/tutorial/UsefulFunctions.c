#include <stdio.h>

typedef int bool;
#define TRUE 1
#define FALSE 0

int StringLen( char[] );
int IsIt42( int );

int main( void )
{
	char test[20] = "Do. Or do not.";  // Length = 14
	printf( "String has length: %d\n", StringLen( test ) );


	int theAnswer = 21;
	if ( IsIt42( theAnswer ) )
	{
		printf( "The answer is 42.\n" );
	}
	else
	{
		printf( "What? That can't be right...\n" );
	}


	return 0;
}

int StringLen( char s[] )
{
	// TODO
	return 0;
}

bool IsIt42( int val )
{
	return (val==42);
}
