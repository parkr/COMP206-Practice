#include <stdio.h>

int main( void )
{
	char animal[50];
	char place[50];
	char verb[50];
	int timeAmount;
	char timeUnit[50];

	

	MadLibs( animal, place, verb, timeAmount, timeUnit );

	return 0;
}

//  "One day, a ________ went to _______ and ____________ another ________ for ________ ___________."
//               animal           place       past-tense           animal       number   time unit
//                name                           verb               name


void MadLibs( char animalName[], char place[], char verb[], int time, char timeUnit[] )
{
	printf( "One day, a %s went to %s and %s another %s for %d %s.\n", animalName, place, verb, animalName, time, timeUnit );
}
