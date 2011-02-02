/***** THERE SEEMS TO BE A PROBLEMO WITH THIS ONE. SAYS "data" AND "next" ARE NOT PART OF THE STRUCT *****/

/* This example can be found on page 114 of Software Systems by J. Vybihal */
#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int data;
	struct NODE *next;
};

int main(void){ /* Add the following integers into a linked list */
	struct NODE *head = NULL, *temp;
	int value;
	
	printf("Enter integer numbers to the list, Enter zero to quit: ");
	scanf("%d", &value);
	
	while(value != 0){
		temp = (struct NODE *) malloc(sizeof(struct NODE));
		temp.data = value;
		
		if(head == NULL) temp.next = NULL;
		else temp.next = head;
		
		head = temp;
		
		printf("Next value: ");
		scanf("%d", &value);
	}
	
	printf("Dump the contents of the linked list:\n");
	for (temp=head; temp!=NULL; temp=temp.next)
		printf("Data = %d\n", temp.data);
	
	return 0;
}