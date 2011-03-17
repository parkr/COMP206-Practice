/*
 *  menu.c
 *  passweb
 *
 *  Created by Parker Moore on 3/7/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

int menu(userlist *users){
	system("clear"); // Clears the terminal (aesthetics!)
	printf("Welcome.\n");
	char * username = malloc(sizeof(char)*100);
	char * password = malloc(sizeof(char)*100);
	char * usertype = malloc(sizeof(char)*100);
	unsigned char c;
	do {
		c = getMenuChoice();
		switch (c) {
			case 48:
				break;
			case '1':
				// Code to add a user using the menu.
				#ifdef DEBUG
				printf("Add.\n");
				#endif
				fflush(stdin);
				username = getUsername();
				password = getPassword();
				usertype = getUsertype();
				add(users, username, password, usertype);
				getc(stdin); // Junk collection!
				break;
			case '2':
				// Code to edit a user using the menu.
				#ifdef DEBUG
				printf("Edit.\n");
				#endif
				printf("First, I'll ask for the credentials of the user you wish to edit.\n");
				username = getUsername();
				password = getPassword();
				usertype = getUsertype();
				printf("Next, I'll need the new information you wish to replace it with.\nNote: this data will overwrite the other data.\n");
				char * username2 = malloc(sizeof(char)*100);
				char * password2 = malloc(sizeof(char)*100);
				char * usertype2 = malloc(sizeof(char)*100);
				username2 = getUsername();
				password2 = getPassword();
				usertype2 = getUsertype();
				edit(users, username, password, usertype, username2, password2, usertype2);
				free(username2);
				free(password2);
				free(usertype2);
				getc(stdin); // Junk collection!
				break;
			case '3':
				// Code to delete a user using the menu.
				#ifdef DEBUG
				printf("Delete.\n");
				#endif
				fflush(stdin);
				username = getUsername();
				del(users, username);
				getc(stdin); // Junk collection!
				break;
			case '4':
				// Code to verify a user using the menu.
				#ifdef DEBUG
					printf("Verify.\n");
				#endif
				username = getUsername();
				password = getPassword();
				#ifdef DEBUG
					printf("\n%s %s\n", username, password);
				#endif
				if(verify(users, username, password) == EXIT_SUCCESS){
					printf("VALID.\n");
				}else{
					printf("INVALID.\n");
				}
				getc(stdin); // Junk collection!
				break;
#ifdef DEBUG
			case '5':
				// Code to print the list of users.
				printf("Printing them.\n");
				int pu=0;
				for (pu=0; pu<users->length; pu++) {
					print_user(users->entries[pu]);
				}
				break;
#endif
			default: printf("That is not an option. Please try again.\n");
				break;
		}
	}while(c != '0');
	system("clear");
	free(username);
	free(password);
	free(usertype);
	return EXIT_SUCCESS;
}

/*
 * This method prints the menu.
 */
void printMenu(void){
	printf("-------------------------\nPlease select and option:\n0. Exit\n1. Add\n2. Edit\n3. Delete\n4. Verify\nPlease enter your choice and press enter: ");
}

/*
 * This method gets the menu choice from the user.
 */
char getMenuChoice(void){
	unsigned char c;
	printMenu();
	c = getc(stdin);
#ifdef DEBUG
	printf("Your choice: %d\n", c);
#endif
	if(c != '0'){
		getc(stdin);
		// This gets the "enter" key ('\r') and eats it so the loop isn't continued.
	}
	return c;
}

/* 
 * This method gets the username from the user.
 */
char * getUsername(void){
	char * username = malloc(sizeof(char)*100);
	printf("Username: ");
	scanf("%s", username);
	return username;
}

/* 
 * This method gets the password from the user.
 */
char * getPassword(void){
	char * password = malloc(sizeof(char)*1000);
	printf("Password: ");
	scanf("%s", password);
	return password;
}

/* 
 * This method gets the usertype from the user.
 */
char * getUsertype(void){
	char * usertype = malloc(sizeof(char)*100);
	printf("Usertype: ");
	scanf("%s", usertype);
	return usertype;
}