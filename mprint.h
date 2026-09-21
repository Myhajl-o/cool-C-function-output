#ifndef MPRINT_H
#define MPRINT_H

int size(char*str_p);
void move_to_char(int num, char*msg,int*i_msg);
void dmove_to_char(double num, char*msg,int*i_msg);
int is_term(char*name);
int mprint(char*name_f,char*text,...);
int mprintp(char*name_f,char*text,void*args);

#endif
