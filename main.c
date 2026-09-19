
#include "mprint.h"



int 
main()
{
  int age = 19,age1 = 16;
  int out;
  char great[] = "Hi fantastic, cocacolastic";
  char end_line = '\n';

  out = mprint("terminal","My age is: %d and age my yonger brother is: %d\n",age,age1);
  mprint("terminal","Result: %d\n",out);

  mprint("terminal","___%s%c",great,end_line);

  return 0;
}

