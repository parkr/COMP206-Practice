#include <stdio.h>

int main(void){
	char *x = "bob";
	*(x+3) = "\n";
	printf("%s", x);
}
