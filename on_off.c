#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "on_off.h"
void tesst(char * c)
{

	int n;
	n = atoi(c);
///	printf("%s",c);
	
///	if (n ==2){
///		printf("rrrr");
///		}
///printf("%s"f);
}	
void on_off (char * v)
{
	int st;
	st = atoi (v);
	if (st > 9 | st < 1){
		printf("Wrong arguments\n");
	}	
	int a;
	switch (st){
		case (1):
			a = 1;
			wr(a);
			diods(a);
			break;
		case (2):
			a = 2;
			wr(a);
			diods(a);
			break; 
		case (3):
			a = 3;
			wr(a);
			diods(a);
			break; 
		case (4):
			a = 4;
			wr(a);
			diods(a);
			break;
		case (5):
			a = 1;
			wr(a);
			diods(a);
			a = 2;
			wr(a);
			diods(a);
			break;
		case (6):
			a = 3;
			wr(a);
			diods(a);
			a = 4;
			wr(a);
			diods(a);
			break;
			
		case (7):
			sst();
			break;		
			
		case (8):
			for(int i = 0; i < 10;i++){
				printf("BLUE\n");
				sleep(1);
				printf("RED\n");
				sleep(1);
				i = i + 1; 
			}
			break;			
	}
	
}

int wr(int w)
{
	FILE *file1, *file2;
	file1 = fopen("my_file1.txt", "a");
	file2 = fopen("my_file2.txt", "a");
	
	if (file1 == NULL || file2 == NULL){
		printf("not open\n");
		return 1;
	}
	
	int y = w;
	if (y == 1 || y == 3){
		fprintf(file1,"%d\n", y);
	}else if (y == 2 || y == 4){
		fprintf(file2,"%d\n", y);
	}
	fclose(file1);
	fclose(file2);
	return 0;
}

int sst()
{
	FILE *file1, *file2;
	file1 = fopen("my_file1.txt", "r");
	file2 = fopen("my_file2.txt", "r");
	if (file1 == NULL || file2 == NULL){
		printf("not open\n");
		return 1;
	}
	int y;
	int array[2];
	int lastNumber1 = 0;
	int lastNumber2 = 0;
	int currentNumber;

	while (fscanf(file1, "%d", &currentNumber) != EOF){
		lastNumber1 = currentNumber;
	}
	
	while (fscanf(file2, "%d", &currentNumber) != EOF){
		lastNumber2 = currentNumber;
	}	
;
	array[0] = lastNumber1;
	array[1]= lastNumber2;
	
	printf("status:\n");
	for(int i = 0; i < 2; i++)
		diods(array[i]);
			
	fclose(file1);
	fclose(file2);
	return 0;
		
}

int diods(int a)
{	
	switch(a){
		case (1):
			printf("blue diod is on\n");
			break;
		case (2):
			printf("red diod is on\n");
			break;	
		case (3):
			printf("blue diod is off\n");
			break;
		case (4):
			printf("red diod is off\n");
			break;	
	}		
}















