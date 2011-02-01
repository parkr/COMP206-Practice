#include <stdio.h>
int main(void){
	int i; /* can also say "int i=1" in for loop, but limits scope to the for loop */
	for(i=1; i<=10; i++){
		printf("%d\n", i); 
		/* variable is optional
		 * cannot mix variables and strings, so use the above syntax
		 * example of multiple variables:
		 *	int x = 10;
		 *	char c = 'a';
		 *	printf("x=%d, c=%c", x, c);
		 */
	}
	return 0;
}
