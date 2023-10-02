#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "on_off.h"

char on_off (const char * str)
{
	int b = 0;
	int r = 0;
	if (str == "on blue" ){
		if ( b == 0){
			b = b +1;
			return "blue diod is on";
		}else{
			return "diod is already on";
		}
	}else if (str == "on red"){
		if ( r == 0){
			r = r +1;
			return "red diod is on";
		}else{
			return "diod is already on";
		} 
	}else if (str == "off blue"){
		if ( b == 1){
			b = d - 1;
			return "blue diod is off";
		}else{
			return "diod is already off";
		} 
	}else if (str == "off red"){
		if ( r == 1){
			r = r - 1;
			return "red diod is off";
		}else{
			return "red is already off";
		}
	}else if (str == "on blue and red"){
		if ( r == 0 & b == 0){
			b = b + 1;
			r = r + 1;
			return "red and blue diods is on";
		}else{
			return "one of them is already on";
		}
	}else if (str == "off blue and red"){
		if ( r == 1 & b == 1){
			b = b - 1;
			r = r - 1;
			return "red and blue diods is off";
		}else{
			return "one of them is already off";
		}
	
}				 	
//  int i;
//   for(i = 0; i< strlen (str); i++)
//   	printf ("%c", toupper(str[i]));
   	
//   printf("\n");	















