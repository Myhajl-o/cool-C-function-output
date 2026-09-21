
#include "mprint.h"



int 
main()
{
  int num_i = 10;
  double pi = 3.1415;
  int out = 0;
  char great[] = "Hi fantastic, cocacolastic";
  char end_line = '\n';
/*  void*args[10] = {(void*)num_i,(void*)end_line,(void*)pi,(void*)end_line,(void*)great,(void*)end_line};*/
  

  out += mprint("terminal","num: %d%cpi:  %f%c___%s%c",num_i,end_line,pi,end_line,great,end_line);
  

  mprint("terminal","all_out: %d%c",out,end_line);

  return 0;
}

