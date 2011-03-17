/*
 *  caesar_cipher.c
 *
 *	Parker Moore
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// This is the number of columns.
#undef STRING_SIZE
#define STRING_SIZE 50

// This is the number of rows.
#undef NUM_STRINGS
#define NUM_STRINGS 50

// This is a special code for when the user inputs nothing
#undef EXIT_UNWANTED
#define EXIT_UNWANTED -2

int text_entered = 0;
int encrypted = 0;
char oblivion[10];

/* 
 * This method will initialize the matrix of 50x50 characters to be "empty" and return 0 upon success
 */
int initialize(char *matrix[]){
	int i = 0;
	for(i=0; i < NUM_STRINGS; i++){
		matrix[i] = malloc(STRING_SIZE);
		strcpy(matrix[i], "                                                  \n");
	}
	return EXIT_SUCCESS;
}
/* 
 * This method destroys this program's hold on the spots in memory which were previously allocated. 
 */
int destroy(char *matrix[]){
	int i = 0;
	for(i=0; i<NUM_STRINGS; i++){
		free(matrix[i]);
	}
	return EXIT_SUCCESS;
}

/*
 * This method prints out the menu, asks the user for input and returns the value inputted.
 */
int getSelection(void){
	int selection;
    printf("MAIN MENU\n=========\n1. Input Text\n2. Encrypt\n3. Decrypt\n4. Exit\nSelection: ");
	fflush(stdin);
	scanf("%d", &selection);
	return selection;
}

/*
 *
 */
char apply_shift(char c, int shift){
	char shifted = c;
	if (c >= 65 && c <= 90) { // Between A and Z
		// Apply shift withing the capital letters bound
		shifted = c+shift;
		if (shifted > 90) {
			shifted %= 90;
			shifted += 65;
		}
	}else {
		if (c >= 97 && c <= 122) { // Between a and z
			// Apply shift within the lowercase letters bound
			shifted = c+shift;
			if (shifted > 122) {
				shifted %= 122;
				shifted += 97;
			}
		}
	}
	return shifted;
}

/*
 *
 */
char take_away_shift(char c, int shift){
	char unshifted = c;
	if (c >= 65 && c <= 90) { // Between A and Z
		// Apply shift withing the capital letters bound
		unshifted = c-shift;
		if (unshifted < 65) {
			unshifted += 25;
		}
	}else {
		if (c >= 97 && c <= 122) { // Between a and z
			// Apply shift within the lowercase letters bound
			unshifted = c-shift;
			if (unshifted < 97) {
				unshifted += 25;
			}
		}
	}
	return unshifted;
}

/* 
 * This method outputs the matrix as indicated in the Grid Cipher method (prints each column first, row-by-row)
 */
int output(char *matrix[]){
	int r,c;
	for(r = 0; r < NUM_STRINGS; r++){
		for (c = 0; c < STRING_SIZE; c++) {
			printf("%c", matrix[r][c]);
		}
	}
	printf("\n");
	return EXIT_SUCCESS;
}

/* 
 * This method receives the input from the user for the Grid Caesar Cipher.
 * Note: the input may not exceed 50 characters (per line) and may not exceed 50 lines (constrained to matrix[50][50])
 * Returns the shift value for the Caesar Cipher.
 */
int input(char *matrix[]){
	char yes_or_no;
	if(encrypted){
		printf("Text has been inputted and encrypted. Are you sure you want to overwrite this text? (y/n)");
		scanf("%c", &yes_or_no);
		scanf("%c", &oblivion[0]);
		if (yes_or_no == 'n' || yes_or_no == 'N') {
			return -1; // Indicates that the process did not occur
		}else{
			initialize(matrix);
			encrypted = 0;
		}
	}
	int counter = 0, shift, wants_to_exit = 0;
	char* oblivion = malloc(1);
	printf("\nBefore you input anything, please remember that ONLY alphanumeric characters are allowed.\nThis program will not properly encode your message if you do not abide by this rule.\nThank you in advance.\n\n");
	printf("Input your phrase to be encrypted:\n");
	fgets(oblivion, STRING_SIZE, stdin);
	while (counter < NUM_STRINGS && !wants_to_exit) {
		printf("%2d: ", (counter+1));
		fgets(matrix[counter], STRING_SIZE, stdin);
		counter++;
		if (matrix[counter-1][0] == 10) {
			wants_to_exit = 1;
		}
	}
	if(matrix[counter][0] == 10 && counter == 0){
		printf("You have chosen not to input anything. This program will be terminated.\n");
		text_entered = 0;
		return EXIT_UNWANTED;
	}
	printf("Next, input the shift number: ");
	scanf("%d", &shift);
	text_entered = 1; // Setting this to "true" so that encryption can occur!
	return shift;
}

/* 
 * This method encrypts the input from the user using the Simple Caesar Cipher method
 * Precondition: matrix has been populated
 */
int encrypt(char *matrix[], char *temp[], char shift){
	if (text_entered) {
		if(encrypted){
			printf("\nYour data can only be encrypted once. Sorry.\n\n");
			return EXIT_FAILURE;
		}else{
			int i, k;
			// Simple Caesar Cipher
			for (i = 0; i < NUM_STRINGS; i++) {
				for (k = 0; k < STRING_SIZE; k++) {
					//shift to the right!
					matrix[i][k] = apply_shift(matrix[i][k], shift);
				}
			}
			// Grid Cipher
			int r = 0, c = 0;
			for (r = 0; r < NUM_STRINGS; r++){
				for(c = 0; c < STRING_SIZE; c++){
					//printf("[%d][%d]\n", r, c); // debugging code
					temp[c][r] = matrix[r][c]; // Switch them up.
				}
			}
			for (r = 0; r < NUM_STRINGS; r++) {
				for (c = 0; c < STRING_SIZE; c++) {
					matrix[r][c] = temp[r][c]; // Transposes
				}
			}
			output(matrix);
			encrypted = 1; // Now it can be decrypted!
		}
		return EXIT_SUCCESS;
	}else {
		printf("\nYou must enter text before you can encrypt it.\n\n");
		return EXIT_FAILURE;
	}
}

/* 
 * This method decrypts the encrypted data using the Simple Caesar Cipher method (applied backwards, of course)
 */
int decrypt(char *matrix[], char *temp[]){
	if (encrypted) {
		int shift;
		printf("What was that shift number again? ");
		scanf("%d", &shift);
		int i, k;
		// Undo Caesar Cipher
		for (i = 0; i < NUM_STRINGS; i++) {
			for (k = 0; k < STRING_SIZE; k++) {
				//shift to the right.
				matrix[i][k] = take_away_shift(matrix[i][k], shift);
			}
		}
		
		// Undo Grid Cipher
		int r = 0, c = 0;
		for (r = 0; r < NUM_STRINGS; r++){
			for(c = 0; c < STRING_SIZE; c++){
				//printf("[%d][%d]\n", r, c); // debugging code
				temp[c][r] = matrix[r][c]; // Switch them up.
			}
		}
		for (r = 0; r < NUM_STRINGS; r++) {
			for (c = 0; c < STRING_SIZE; c++) {
				matrix[r][c] = temp[r][c]; // Transposes
			}
		}
		
		output(matrix);
		
		encrypted = 0;
		return EXIT_SUCCESS;
	}else{
		printf("\nYou have to encrypt your data before you can decrypt it!\n\n");
		return EXIT_FAILURE;
	}
}

int main(void){
	char* matrix[STRING_SIZE][NUM_STRINGS];
	char* temp[NUM_STRINGS][STRING_SIZE];
	initialize(*matrix);
	initialize(*temp);
	int the_selection = -1, shift = -1;
	while (the_selection != 4) {
		the_selection = getSelection();
		switch (the_selection) {
			case 1:
				shift = input(*matrix);
				break;
			case 2:
				encrypt(*matrix, *temp, shift);
				break;
			case 3:
				decrypt(*matrix, *temp);
				break;
			case 4:
				printf("You are now exiting the Grid Caesar Cipher program.\n");
				break;
			default:
				printf("\tThat is not a valid option. Please try again.\n");
				break;
		}
		if(shift == EXIT_UNWANTED){
			the_selection = 4;
			printf("You are now exiting the Grid Caesar Cipher program.\n");
		}
	}
	destroy(*temp);
	destroy(*matrix);
	return EXIT_SUCCESS;
}
