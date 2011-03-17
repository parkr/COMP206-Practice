/*
 *  passweb.c
 *  passweb
 *
 *  Created by Parker Moore on 3/7/11.
 *  Copyright 2011 Parker Moore. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "passweb.h"
#include "cipher.h"
#include "menu.h"

int main (int argc, const char * argv[]) {
	//Declare variables
	FILE *file;
	userlist users;
	char * encrypted_data = malloc(sizeof(char)*10000);
	char * decrypted_data = malloc(sizeof(char)*10000);
	char * buffer = malloc(sizeof(char)*10000);
	
	// Print an error if there aren't enough arguments.
	if(argc <= 1){
		printf("Syntax error: insufficient arguments.\n");
		help();
		return EXIT_FAILURE;
	}
	
	if(file_exists("password.csv")){
		// Reads in the encrypted file.
		file = fopen("password.csv", "r");
		char start;
		//start = 3; // Ignore. My way of encrypting the file that was made by hand.
		if(start == 3){ // Unencrypted file needs to be encrypted.
			while (!feof(file)) {
				fgets(buffer, sizeof(buffer), file);
				c_encrypt(buffer);
				strcat(encrypted_data, buffer);
			}
			fclose(file);
			file = fopen("encrypted.csv", "w+");
			fprintf(file, "%s", encrypted_data);
			free(encrypted_data);
			exit(EXIT_SUCCESS);
		}else{ // Encrypted file needs to be decrypted.
			while (!feof(file)) {
				fgets(buffer, sizeof(buffer), file);
				c_decrypt(buffer);
				strcat(decrypted_data, buffer);
			}
			fclose(file);
			// Write to temporary file so the data can be retrieved by the program.
			file = fopen("temp_read.csv", "w+");
			fprintf(file, "%s", decrypted_data);
			free(decrypted_data);
		}
		fclose(file);
		// Read the decrypted file into the struct.
		file = fopen("temp_read.csv", "r");
		int i = 0;
		while (!feof(file) && i < 1000) {
			users.entries[i].username = malloc(sizeof(char)*100);
			users.entries[i].password = malloc(sizeof(char)*1000);
			users.entries[i].usertype = malloc(sizeof(char)*100);
			fscanf(file, "%s", users.entries[i].username);
			fscanf(file, "%s", users.entries[i].password);
			fscanf(file, "%s", users.entries[i].usertype);
			users.entries[i].username[strlen(users.entries[i].username)-1] = '\0';
			users.entries[i].password[strlen(users.entries[i].password)-1] = '\0';
			i++;
		}
		users.length = i-1;
		fclose(file);
		unlink("temp_read.csv"); // Delete temporary file!
	}else{
		// No need to create the file here - all the information will be written at the end of the program.
		users.length = 0; // (No entries in DB)
	}
	
	if(strcmp(argv[1], "-menu") == 0){
		// Start the menu!
		menu(&users);
	}else{
		if(strcmp(argv[1], "-add") == 0) {
			// Code to add the entry. Error checking, too.
			if(argc >= 5){
				#ifdef DEBUG
					printf("Adding...\n");
				#endif
				if(not_a_switch(argv[2]) && not_a_switch(argv[3]) && not_a_switch(argv[4])){
					add(&users, argv[2], argv[3], argv[4]);
				}else {
					printf("Whoops! Looks like one of your arguments is a switch. Try that again!\n");
					printf("(Use -help to print out the help menu.)\n");
				}
			}else{
				printf("Syntax error: insufficient arguments.\nUse switch '-help' for further instructions.\n");
				return EXIT_FAILURE;
			}
		}else{
			if(strcmp(argv[1], "-del") == 0){
				// Code to delete an entry. Error checking here, too.
				if(argc >= 3){
					#ifdef DEBUG
					printf("Deleting...\n");
					#endif
					if(not_a_switch(argv[2])){
						del(&users, argv[2]);
					}else{
						printf("Whoops! Looks like one of your arguments is a switch. Try that again!\n");
						printf("(Use -help to print out the help menu.)\n");
					}
				}else {
					printf("Syntax error: insufficient arguments.\nUse switch '-help' for further instructions.\n");
					return EXIT_FAILURE;
				}
			}else{
				if(strcmp(argv[1], "-edit") == 0){
					// Code to edit an entry. Error checking included.
					if(argc >= 8){
						#ifdef DEBUG
						printf("Editing...\n");
						#endif
						if (not_a_switch(argv[2]) && not_a_switch(argv[3]) && not_a_switch(argv[4]) && not_a_switch(argv[5]) && not_a_switch(argv[6]) && not_a_switch(argv[7])) {
							edit(&users, argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
						}else {
							printf("Whoops! Looks like one of your arguments is a switch. Try that again!\n");
							printf("(Use -help to print out the help menu.)\n");
						}
					}else {
						printf("Syntax error: insufficient arguments.\nUse switch '-help' for further instructions.\n");
						return EXIT_FAILURE;
					}

				}else{
					if(strcmp(argv[1], "-verify") == 0){
						// Code to verify an entry. Error checking is important.
						#ifdef DEBUG
						printf("Verifying...\n");
						#endif
						if(argc >= 4){
							if (not_a_switch(argv[2]) && not_a_switch(argv[3])) {
								return verify(&users, argv[2], argv[3]);
							}else {
								printf("Whoops! Looks like one of your arguments is a switch. Try that again!\n");
								printf("(Use -help to print out the help menu.)\n");
								
							}
						}else{
							printf("Syntax error: insufficient arguments.\nUse switch '-help' for further instructions.\n");							
							return EXIT_FAILURE;
						}
					}else{
						if(strcmp(argv[1], "-help") == 0){
							// Added a -help switch just in case it was needed.
							help();
						}else{
							// Print an error that the switch used is not defined and print the help menu.
							printf("Syntax error: undefined (%s)\n", argv[1]);
							help();
						}
					}
				}
			}
		}
	}
	// Writing the data in the userlist to a file as-is. (Later encrypted.)
	#ifdef DEBUG
	printf("Writing to file...\n");
	#endif
	file = fopen("temp_write.csv", "w+");
	int usr;
	for (usr = 0; usr < users.length; usr++) {
		if(strcmp(users.entries[usr].usertype, "deleted") != 0){
			fprintf(file, "%s", users.entries[usr].username);
			fprintf(file, ", ");
			fprintf(file, "%s", users.entries[usr].password);
			fprintf(file, ", ");
			fprintf(file, "%s", users.entries[usr].usertype);
			fprintf(file, "\n");
		}
		free(users.entries[usr].username);
		free(users.entries[usr].password);
		free(users.entries[usr].usertype);
	}
	fclose(file);
	// Encrypt the data that was previously written to the temporary file.
	file = fopen("temp_write.csv", "r+");
	while (!feof(file)) {
		fgets(buffer, sizeof(buffer), file);
		c_encrypt(buffer);
		strcat(encrypted_data, buffer);
	}
	fclose(file);
	// Write encrypted data to the password.csv file to be used the next time the program runs.
	file = fopen("password.csv", "w+");
	fprintf(file, "%s", encrypted_data);
	fclose(file);
	free(buffer);
	free(encrypted_data);
	unlink("temp_write.csv"); // Get rid of the temp file.
	return EXIT_SUCCESS;
}

/*
 * This method writes the help menu that gives information to the user about syntax and required arguments, etc.
 */
int help(){
	printf("\nSyntax: ./passweb [-menu][-add][-edit][-del][-verify] username password user-type [username2 password2 user-type2]\n");
	printf("Note: Only one switch can be used at once.\n\n");
	printf("\t-menu:\tThis switch displays the menu with options to choose from.\n\t\tYou may perform as many actions as you wish in this menu.\n\n");
	printf("\t-add:\tThis switch adds a user to the database.\n\t\tIt requires 'username', 'password' and 'user-type' as its arguments.\n\t\tIf the user already exists, it will not be added.\n\n");
	printf("\t-edit:\tThis switch edits a user in the database.\n\t\tIt requires all the arguments above for both users.\n\t\tIf the user doesn't exist, it cannot be edited and no changes will be made.\n\n");
	printf("\t-del:\tThis switch deletes a user from the database.\n\t\tIt requires only the username argument.\n\t\tIf the username doesn't exist in the database, an error message will be displayed and nothing will occur.\n\n");
	printf("\t-verify:This switch verifies a user in the databse.\n\t\tIt requires the username and password arguments only.\n\t\tThe program will notify the user whether or not the username and password match an entry in the database.\n\t\tNote that if the username is found, the password must match that username's password.\n\n");
	printf("\t-help:\tThis switch prints out this help menu.\n\n");
	return EXIT_SUCCESS;
}

/*
 * This method checks to see if the filename exists.
 */
int file_exists(const char * filename){
	FILE * file;
	if((file = fopen(filename, "r"))){
		fclose(file);
		return (TRUE);
	}else{
		return (FALSE);
	}
}

/*
 * This method checks to see if the user exists in the userlist.
 * Note, this method only checks to see if the username exists in the list, not any other field.
 * It returns the user's position in the list if it does exist, or a -1 if it doesn't.
 */
int user_exists(userlist * users, const char * username){
	int pos;
	for(pos = 0; pos < users->length; pos++){
		#ifdef DEBUG
		printf("%d: %s %s\n", pos, users->entries[pos].username, username);
		#endif
		if (strcmp(users->entries[pos].username, username) == 0) {
			if(strcmp(users->entries[pos].usertype, "deleted") != 0){ // Check if it's been deleted in this session (menu problem only)
				return pos;
			}
		}
	}
	return -1;
}

/*
 * Prints the user's information to standard out.
 */
int print_user(user usr){
	printf("Username: %s | Password: %s | User Type: %s\n", usr.username, usr.password, usr.usertype);
	return EXIT_SUCCESS;
}

/*
 * Adds the user to the list if and only if:
 *		1. the user doesn't already exist
 *		2. the usertype is a 'user' or 'sysop'
 *		3. there are less than 999 users already in the list
 */
int add(userlist *users, const char * username, const char * password, const char * usertype){
	if(user_exists(users, username) >= 0){
		printf("The user already exists! It was not added.\n");
		return EXIT_FAILURE;
	}else{
		if((strcmp(usertype, "user") == 0) || (strcmp(usertype, "sysop")) == 0){
			if (users->length < 999) { // Due to the restriction in my struct, only 1000 users can exist.
				users->entries[users->length].username = malloc(sizeof(char)*100);
				users->entries[users->length].password = malloc(sizeof(char)*1000);
				users->entries[users->length].usertype = malloc(sizeof(char)*100);
				strcpy(users->entries[users->length].username, username);
				strcpy(users->entries[users->length].password, password);
				strcpy(users->entries[users->length].usertype, usertype);
				users->length++;
				#ifdef DEBUG
				printf("Added: %s %s %s\n", users->entries[users->length-1].username, users->entries[users->length-1].password, users->entries[users->length-1].usertype);
				#endif
				return EXIT_SUCCESS;
			}else {
				printf("You may not have more than 1000 users.\n");
				return EXIT_FAILURE;
			}
		}else{
			printf("Your user type must be either 'user' or 'sysop'. Nothing else.\n");
			return EXIT_FAILURE;
		}
	}
}

/*
 * Edits the user's data. Requires ALL of the existing user's data AND ALL of the fields, whether changes are made or not.
 * If the user doesn't exist, an error will be printed and it will leave the data unchanged.
 */
int edit(userlist *users, const char * username1, const char * password1, const char * usertype1, const char * username2, const char * password2, const char * usertype2){
	int pos;
	if((pos = user_exists(users, username1)) >= 0){
		strcpy(users->entries[pos].username, username2);
		strcpy(users->entries[pos].password, password2);
		strcpy(users->entries[pos].usertype, usertype2);
		return EXIT_SUCCESS;
	}else{
		printf("The user doesn't exist.\n");
		return EXIT_FAILURE;
	}
}
	
/*
 * Deletes a user. Requires only the username from the command line (not any other parameters) and a pointer to the userlist.
 * If the user doesn't exist, an error will be printed. No data in the user list will be editied.
 */
int del(userlist * users, const char * to_delete){
	int pos;
	if((pos = user_exists(users, to_delete)) >= 0){
		strcpy(users->entries[pos].usertype, "deleted"); // This is a personal convention which means that the user doesn't exist.
														 // This will not be written to the file. (because the user won't be either!)
		#ifdef DEBUG
		print_user(users->entries[pos]);
		#endif
		return EXIT_SUCCESS;
	}else{
		printf("The user doesn't exist.\n");
		return EXIT_FAILURE;
	}
}
	
/*
 * Verifies the user & its password based. If the user exists in the list AND the password that was inputted matches that user's password,
 *		it will return EXIT_SUCCESS. Otherwise, it will return EXIT_FAILURE.
 * If the user doesn't exist, an error will be printed and it will leave the data unchanged.
 */
int verify(userlist * users, const char * username, const char * password){
	int pos;
	if((pos = user_exists(users, username)) >= 0){
		if(strcmp(users->entries[pos].password, password) == 0){
			return EXIT_SUCCESS;
		}else{
			return EXIT_FAILURE;
		}
	}else{
		#ifdef DEBUG
		printf("The user doesn't exist.\n");
		#endif
		return EXIT_FAILURE;
	}
}

/*
 * Checks to see if an input is a switch (text preceded by a '-' character). Returns 0 if the '-' is present input-initially and any other value if it is not.
 */
int not_a_switch(const char * input){
	return strncmp(input, "-", 1);
}
