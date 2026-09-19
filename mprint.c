
#include "mprint.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>

#include <stdarg.h>

#define PERMS 0775




int mprint(char*name_f,char*text,...)
{
  int file;
  int count_sym = 0;
  int current_sym = 0;

  int int_arg;
  char*str_arg;
  char char_arg;
  int size_arg;
  char int_str[12];

  va_list arg_p;

  va_start(arg_p,text);

  if(is_term(name_f))
  {
    file = 1;
  }
  else
  {
    file = open(name_f,O_WRONLY,0);
    if(file == -1)
    {
      file = creat(name_f,PERMS);
      if(file == -1)
        return -1;
    }
  }

  for(int i = 0;;i++)
  {
    if(text[i] == '%' && 
    (text[i+1] == 'd' || text[i+1] == 's' || text[i+1] == 'c'))
    {
      write(file,text+current_sym,i-current_sym);
      
      switch (text[i+1])
      {
        case 'd':
          size_arg = 0;
          int_arg = va_arg(arg_p,int);
          move_to_char(int_arg,int_str,&size_arg);
          write(file,int_str,size_arg);
          break;

        case 's':
          str_arg = va_arg(arg_p,char*);
          size_arg = size(str_arg);
          write(file,str_arg,size_arg);
          break;

        case 'c':
          size_arg = 1;
          char_arg = (char)va_arg(arg_p,int);
          write(file,&char_arg,size_arg);
          break;
      }

      i++;
      count_sym += size_arg;
      current_sym = i + 1;
      continue;
    }
    
    count_sym++;
    if(!text[i])
    {
      write(file,text+current_sym,i-current_sym);
      va_end(arg_p);
      return count_sym;
    }
  }
}





int size(char*str_p)
{
    int count = 0;
    for(char*p = str_p;*p;p++)
    {
        count++;
    }
    return count;
}

void move_to_char(int num, char*msg,int*i_msg)
{
  char s[12];
  int i = 11;
  int j = 0;
  char sub = 0;
  if(num < 0)
  {
    sub = !sub;
    num = -num;
  }
  if(!num)
  {
    s[i--] = '0';
  }
  else
  {
    for(;num;num/=10)s[i--] = num%10 + '0';
  }
  if(sub)s[i--] = '-';
  for(; j < (11 - i); j++)msg[(*i_msg)++] = s[i + j + 1];
}


int is_term(char*name)
{
  const char*name_term = "terminal\0";
  int i = 0;
  for(;name_term[i] != '\0' && name[i] != '\0';i++)
  {
    if(name_term[i] != name[i]) return 0;
  }
  return 1;
}
