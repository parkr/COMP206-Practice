/* This example can be found on page 106 of Software Systems by J. Vybihal */
#include <stdio.h>
#include <stdlib.h>

int main(void){
	char sentence[80], key2[5], output1[80], output2[80];
	int key1, j, k;
	
	printf("This will encrypt your sentence using two methods.\n");
	printf("Please enter your sentence (up to 79 characters): ");
	scanf("%s", sentence);
	
	printf("A Caesar cipher uses an integer number to scramble letters.\n");
	printf("Please enter an integer number to scrmble the letters with: ");
	scanf("%d", &key1);
	
	printf("A modified Caesar cipher uses a word to scramble the letters.\n");
	printf("Please input a 4-character word with which the above sentence will be scrambled: ");
	scanf("%s", key2);
	
	for(j=0, k=0; j<80 && sentence[j] != '\0'; j++, k=((k+1)%4)){
		output1[j] = (sentence[j] + key1) % 256;
		output2[j] = (sentence[j] + key2[k]) % 256;
	}
	
	printf("Your input sentence is %s", sentence);
	printf(" and key1 is %d while key2 is %s.\n", key1, key2);
	printf("The cipher with key1 is %s ", output1);
	printf(" and with key2 is %s.\n", output2);
	
	return EXIT_SUCCESS;
}
