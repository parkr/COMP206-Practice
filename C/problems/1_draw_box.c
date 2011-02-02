#include <stdio.h>

int main(void){
	int side;
	printf("Perimiter of square: ");
	scanf("%d", &side);

	int i, j, k;
	for(i=0; i<side; i++){
		if(i==0 || i==side-1){
			for(j=0; j<side-1; j++){
				printf("X");
			}
			printf("X\n");
		}else{
			for(k=0; k<side-1; k++){
				if(k==0)
					printf("X");
				else
					printf(" ");
			}
			printf("X\n");
		}
	}
	return 0;
}
