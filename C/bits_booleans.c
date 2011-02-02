/* This is an example from Software Systems by J. Vybihal (p. 109) */
#include <stdio.h>
#include <stdlib.h>
int main (void){
	unsigned int flag = 6; /* i.e. 0110 */
	unsigned int mask = 5; /* i.e. 0101 */
	unsigned int result;
	
	result = flag & mask;
	printf("%d\n", result); /* output is 4, i.e. 0100 */
	
	result = flag ^ mask;
	printf("%d\n", result); /* output is 3, i.e. 0011 */
	
	result = flag | mask;
	printf("%d\n", result); /* output is 7, i.e. 0111 */
	
	result = flag << 1;
	printf("%d\n", result); /* output is 12, i.e. 1100 */
	
	result = flag >> 1;
	printf("%d\n", result); /* output is 3, i.e. 0011 */
	
	if (result % 2) printf("Odd number.\n");
	
	return EXIT_SUCCESS;
}
