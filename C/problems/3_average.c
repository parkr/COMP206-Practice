#include <stdio.h>

int main(void){
	int i, sum=0, temp;
	for(i=0; i<10; i++){
		printf("Please enter a number: ");
	        scanf("%d", &temp);
		sum += temp;
	}
	printf("The average of these numbers is %d.\n", sum/10);
	return 0;
}	
