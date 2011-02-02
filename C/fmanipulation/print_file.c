#include <stdio.h>
#include <stdlib.h>

int main (void){
	
	FILE *in = fopen("names.txt", "rt"), *out = fopen("backup.txt", "wt");
	char buffer[100];

	if( in == NULL || out == NULL ) {
		fclose(in);
		fclose(out);
		return;
	}

	while(!feof(in)){
		fgets(buffer, 100, in);
		fprintf(out, "%s", buffer);
	}
	
	fclose(in);
	fclose(out);

	return 0;
}
