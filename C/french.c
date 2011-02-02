#include <stdio.h>
#include <stdlib.h>

#define FRENCH

int main(void){
	int score[10];
	int name[10];

	#ifdef FRENCH
		printf("Votre Nom: ");
	#else
		printf("Your Name: ");
	#endif

	scanf("%s", name);

	return 0;
}
