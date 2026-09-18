
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>

#define PERMS 0775

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

int mprint(char*name_f,char*text,...)
{
  int file;
  int count_sym = 0;
  int current_sym = 0;

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
    if(text[i] == '%')
    {
      if(text[i+1] == 'd')
      {

      }
      else if(text[i+1] == 's')
      {

      }
      else if(text[i+1] == 'c')
      {

      }
      /*тут повинен формуватися current_sym після того як змінна виведеться*/
    }

    if(text[i] == '\0')
    {
      write(file,text+current_sym,i-current_sym);
    }

  }

}
