#include <stdio.h>

int main(void){
	float grade;

	printf("What is the grade? (percents only): ");
	scanf("%f", &grade);

	if(grade >= 85){
		printf("That's an A!\n");
	}else{
		if(grade<85 && grade>=75){
			printf("That's a B!\n");
		}else{
			if(grade<75 && grade>=65){
				printf("That's a C.\n");
			}else{
				if(grade<65 && grade>=55){
					printf("That's a D.\n");
				}else{
					printf("That's an F. Fail.\n");
				}
			}
		
		}
	}
	return 0;
}
