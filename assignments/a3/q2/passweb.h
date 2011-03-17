/*
 *  passweb.h
 *  passweb
 *
 *  Created by Parker Moore on 3/7/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#define TRUE 1
#define FALSE 0
// Define this if you wish to include debugging code!
#undef DEBUG

// Creates a user structure containing the username, password and usertype.
typedef struct {
	char * username;
	char * password;
	char * usertype;
} user;

// Creates a userlist structure containing an array of users and the length of the userlist (int).
typedef struct {
	user entries[1000]; // Max of 1000 entries
	int length;
} userlist;

int help();
int file_exists(const char * filename);
int initialize_user(user usr);
int user_exists(userlist * users, const char * username);
int print_user(user usr);
int add(userlist *users, const char * username, const char * password, const char * usertype);
int edit(userlist *users, const char * username1, const char * password1, const char * usertype1, const char * username2, const char * password2, const char * usertype2);
int del(userlist * users, const char * to_delete);
int verify(userlist * users, const char * username, const char * password);
int not_a_switch(const char * input);