#include <string.h>
#include <stdio.h>
#include "on_off.h"

int main(int argc,char * argv[])
{  
///   printf( "debug 0: %s\n", argv[1]);
   tesst(argv[1]);
   on_off (argv[1]);
   return 0;
}
