/* This example can be found on page 119 of Software Systems by J. Vybihal
 * Example of Functions, Recursion and Scope
 */
#include <string.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

char theWord[50], newWord[50];

int isPalindrome(char word[]){
	
	char newWord[50];
	if (strlen(word) == 0 || strlen(word)==1) return TRUE;
	if (word[0] != word[strlen(word)-1]) return FALSE;
	
	printf("%s\n", word);
	strncpy(newWord, word+1, strlen(word)-2);
	return isPalindrome(newWord);
	
}

int main (void) {
	printf("Input a word to test: ");
	scanf("%s", theWord);
	if (isPalindrome(theWord)) {
		printf("YES it is a palindrome.\n");
	}else {
		printf("NO it is not a palindrome.\n");
	}

	
	return 0;
}
