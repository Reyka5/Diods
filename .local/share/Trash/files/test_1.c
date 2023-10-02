#include <stdio.h>
int main(){
	FILE *file;
	file = fopen("my_file.txt", "r");
	
	if (file == NULL){
		printf("not open\n");
		return 1;
	}
	int a;
	fscanf(file,"%d", &a);
	fclose(file);
	printf("aps");
	return 0;
}
