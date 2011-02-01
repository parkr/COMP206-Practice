#include <stdio.h>
int main (void) {
	int age1, age2;
	printf("First age: ");
	scanf("%d", &age1);
	printf("Second age: ");
	scanf("%d", &age2);
	if(age1 > age2){
		printf("The first age is greater than the second age.\n");
	}else{
		if(age1 == age2){
			printf("The ages are equal.\n");
		}else{
			printf("The second age is greater than the first age.\n");
		}
	}
	return 0;
}
