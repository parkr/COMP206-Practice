#include <stdio.h>
#include <string.h>

/* 
 * Precondition: an equal amount of memory has been allocated for each inputted string
 */
int copy(char* source, char* destination){
	int i=0;
	for(i=0; i<strlen(source); i++){
		*(destination+i) = *(source+i);
	}
	// OR
	i=0;
	while(source[i] != '\0'){
		destination[i] = source[i];
		i++;
	}
	// THEN
	destination[i] = '\0';
	printf("%s\n", destination);
	// printf("%s = %s\n", source, destination);
}
