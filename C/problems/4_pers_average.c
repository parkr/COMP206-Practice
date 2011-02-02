#include <stdio.h>

int main(void){
	int sum=0, num=0, input=1;
	printf("You will be asked to enter a series of numbers to be averaged.\nYou have no limit on the number of entries you may enter.\nEnter a non-positive number to exit the input and perform the calculation.\n");
	while(input > 0){
		printf("Enter a number: ");
		scanf("%d", &input);
		if(input > 0){
			sum += input;
			num++;
		}
	}
	printf("The average of the numbers you entered is: %d\n", sum/num);
	
	return 0;
}
