#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define BLUE (1 << 0)
#define RED (1 << 1)
#include "on_off.h"

int leds;

void swit (int led, int state){
	
	if (state) {
        	leds |= led; 
    	}else {
        	leds &= ~led; 
    	}
    	wr(leds);
}

	
void on_off (char * v)
{
	int st = atoi (v);	
	switch (st){
		case (1):
		    	swit(BLUE, 1);
		    	diods();
		    	break;
		case (2):
		    	swit(RED, 1);
		    	diods();
		    	break;
		case (3):
			swit(BLUE, 0);
			diods();
			break;
		case (4):
			swit(RED, 0);
			diods();
			break;
		case (5):
			swit(BLUE, 1);
			swit(RED, 1);
			diods();
			break;
		case (6):
		    	swit(BLUE, 0);
		    	swit(RED, 0);
		    	diods();
		    	break;
		case (7):
			sst();
			break;		
		case (8):
			srand(time(NULL));
			int min = 1;
			int max = 10;
			for(int i = 0; i < 10;i++){
				int random = min + rand() % (max - min + 1);
				printf("BLUE\n");
				sleep(random);
				random = min + rand() % (max - min + 1);
				printf("RED\n");
				sleep(random);
				i = i + 1; 
			}
			break;
		case (9):
			clean();
			wr(0);
			break;	
		default:
            		printf("Wrong arguments\n");
            		break; 				
	}
	
}

int clean() {
	
    	const char *filename = "my_file1.txt";

    	FILE *file = fopen(filename, "w"); 
    	if (file == NULL) {
        	perror("Ошибка при открытии файла");
        	return 1;
    	}

    	fclose(file); 

    	printf("Файл \"%s\" очищен.\n", filename);

    	return 0;
}

int wr(int w)
{
	FILE *file1;
	file1 = fopen("my_file1.txt", "a");
//	file2 = fopen("my_file2.txt", "a");
	
	if (file1 == NULL ){
		printf("not open\n");
		return 1;
	}
	leds = w;
	
//	if (w == 1 || w == 3){
		fprintf(file1,"%d\n", leds);
//	}else if (w == 2 || w == 4){
//		fprintf(file2,"%d\n", w);
//	}

	fclose(file1);
//	fclose(file2);
	return 0;
}

int sst()
{
	FILE *file1;
	file1 = fopen("my_file1.txt", "r");
	
	if (file1 == NULL ){
		printf("not open\n");
		return 1;
	}
	
	int lastNumber = 0;
	int currentNumber;

	while (fscanf(file1, "%d", &currentNumber) != EOF){
		lastNumber = currentNumber;
	}	
;
	printf("status:\n");
	
	diods();

	
	fscanf(file1, "%d", &lastNumber);			
	fclose(file1);
	
	return 0;
		
}

void diods(){
    if ((leds & BLUE) && (leds & RED)) {
        printf("Blue and red diods are on\n");
    } else if (leds & BLUE) {
        printf("Blue diod is on, red diod is off\n");
    } else if (leds & RED) {
        printf("Red diod is on, blue diod is off\n");
    } else {
        printf("Blue and red diods are off\n");
    }
}















