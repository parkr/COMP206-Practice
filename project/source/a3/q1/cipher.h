/*
 *  cipher.h
 *  passweb
 *
 *  Created by Parker Moore on 3/7/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#define SHIFT_VALUE 13

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

int c_encrypt(char *text);
int c_decrypt(char *text);