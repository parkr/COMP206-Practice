/*
 *  cipher.c
 *  passweb
 *
 *  Created by Parker Moore on 3/7/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "cipher.h"
#include <stdio.h>
#include <string.h>

int c_encrypt(char *text){
	int c;
	while(*text != '\0') {
		//printf("%c->", *text);
		c = *text+SHIFT_VALUE;
		if(c > 255){
			c %= 255;
		}
		*text = c;
		text++;
		//printf("%c\n", c);
	}
	//printf("\n");
	return EXIT_SUCCESS;
}

int c_decrypt(char *text){
	int c;
	while(*text != '\0') {
		//printf("%c->", *text);
		c = *text-SHIFT_VALUE;
		if(c <= 0){
			c += 256;
		}
		*text = c;
		text++;
		//printf("%c\n", c);
	}
	//printf("\n");
	return EXIT_SUCCESS;
}