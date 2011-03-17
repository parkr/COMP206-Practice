/*
 *  login.c
 *  login
 *
 *  Created by Parker Moore on 3/9/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 *	NOTE: "passweb" binary must exist in this directory. If you made any changes to a password.csv, make sure to copy it over to this directory too.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
	char * username = malloc(sizeof(char)*100);
	char * password = malloc(sizeof(char)*1000);
	printf("Username: ");
	scanf("%s", username);
	printf("Password: ");
	scanf("%s", password);
	char * command = malloc(sizeof(char)*1000);
	strcpy(command, "./passweb -verify ");
	strcat(command, username);
	strcat(command, " ");
	strcat(command, password);
	int returned = system(command);
	if(returned == EXIT_SUCCESS){
		printf("Verified!\n");
	}else {
		printf("Invalid!\n");
	}
	return EXIT_SUCCESS;
}