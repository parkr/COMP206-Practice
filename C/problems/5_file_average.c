#include <stdio.h>

int main(void){
	int sum=0, num=0, input=1;
	FILE *in = fopen("grades.txt", "rt");
        while(!feof(in)){
                fscanf(in, "%d", &input);
                if(input > 0){
                        sum += input;
                        num++;
                }
        }
        printf("The average of the numbers in 'grades.txt' is: %d\n", sum/num);

        return 0;
	
}
