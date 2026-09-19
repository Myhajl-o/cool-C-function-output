
#include "mprint.h"



int 
main()
{
  int age = 19;
  int out;

  out = mprint("terminal","My age is: %d\n",age);
  mprint("terminal","Result: %d\n",out);

  return 0;
}

