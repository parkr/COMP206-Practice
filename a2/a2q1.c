/*
 *  a2q1.c
 *  
 *
 *  Created by Parker Moore on 2/8/11.
 *	COMP206 Assignment 2, Question 1
 *	Student ID: 260405646
 *
 */

#include <stdio.h>

int main (void) {
    char c, empty;
	printf("Welcome to ASCII:\n");
	while (c != '0' && c != 48 && c != 10){
		printf("----> ");
		scanf("%c", &c); // Get the char from the user.
		scanf("%c", &empty); // This reads the \n that exists at the end of the previous character input. This bug is annoying.
		printf("ascii: %d\n", c); // Print the ASCII code of the inputted char above (not the newline character)
	}
	printf("Done.\n");
    return 0;
}
