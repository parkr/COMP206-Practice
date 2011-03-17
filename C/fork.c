#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main (void){
	printf("Hello. Before fork.\n");
	printf("Hello. Again, before fork.\n");
	int x = fork();
	char * hello = malloc(sizeof(char)*10000);
	if(x == 0){
		strcpy(hello, "child, baby.");
	}else{
		strcpy(hello, "parent.");
	}
	printf("Done with the %s\n", hello);
	return 0;
}
