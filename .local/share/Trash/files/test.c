#include <stdio.h>
int main(){
	FILE *file;
	file = fopen("my_file.txt", "w");
	
	if (file == NULL){
		printf("not open\n");
		return 1;
	}
	int a = 5;
	fprintf(file,"%d", a);
	fclose(file);
	printf("aps");
	return 0;
}
