/* This example can be found on page 111 of Software Systems by J. Vybihal */
#include <stdio.h>

struct STUD_REC {
	char name[30];
	int age;
	double gpa;
} john;
	
struct STUD_REC studs[10];

int main(void){
	int i;
	printf("Enter info:\n");
	scanf("%s", &john.name);
	scanf("%d", &john.age);
	scanf("%f", &john.gpa);
	
	printf("Enter info for all students:\n");

	for(i=0; i<10; i++){
		scanf("%s", &(studs[i].name));
		scanf("%d", &(studs[i].age));
		scanf("%f", &(studs[i].gpa));
	}
	
	return 0;
}
