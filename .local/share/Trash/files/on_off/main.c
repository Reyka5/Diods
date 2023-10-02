#include <string.h>
#include <stdio.h>
#include "on_off.h"

int main(int argc, char ** argv)
{
   if (argc <2){
      fprintf(stderr, "Wrong argument\n");
      return 1;
   }
   on_off (argv[1]);
   return 0;
}
