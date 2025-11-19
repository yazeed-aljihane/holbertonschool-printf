#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void PrintChar (va_list *args , int *totalb)
{

char c  = va_arg(*args,int);
write(1,&c,1);
*totalb += 1;
}
void PrintString(va_list *args, int *totalb)
{
char *string = va_arg(*args,char*);
write(1,string,strlen(string));
*totalb += strlen(string);
}



int _printf(const char *format, ...)
{
int i, j;
va_list args;
int totalb = 0;
int check = 0;
type tp[] = 
{
{'c',PrintChar},
{'s',PrintString}
};

va_start(args,format);
i = 0;
while (format&&format[i])
{
if (format[i] == '%')
{
j = 0;
while (j < 2)
{
if (format[i + 1] == tp[j].s)
{
tp[j].fun(&args, &totalb);
i+=2;
check = 1;
break;
}
j++;
}
}
if (check == 0)
{
write(1,&format[i],1);
totalb += 1;
i++;
}
check = 0;
}
va_end(args);
return (totalb);
}
