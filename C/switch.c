/* This example is found on page 104 of Software Systems by J. Vybihal */
#include <stdio.h>
int main (void) {
	int x;
	scanf("%d", &x);
	
	switch(x){
		case 0:
			printf("No customers.\n");
			break;
		case 2:
			printf("Maximum.\n");
		default:
			printf("Illegal value.\n");
	}
	return 0;
}
