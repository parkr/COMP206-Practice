/*
 *  menu.h
 *  passweb
 *
 *  Created by Parker Moore on 3/7/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#define MAX(x,y) ((x > y) ? (x) : (y))

int menu(userlist *users);
void printMenu(void);
char getMenuChoice(void);
char * getUsername(void);
char * getPassword(void);
char * getUsertype(void);