#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 1024




void PrintUdecmile(va_list *args, int *totalb, char *bufferr ,int *index)
{
	int i = 0, j;
 unsigned int number = va_arg(*args, unsigned int);
 char buffer[BUF_SIZE];

 if (*index == 1024)
 {
 write(1, bufferr, *index);
 *index = 0;
 }
if (number == 0)
{
bufferr[*index] = '0';
(*index)++;
*totalb += 1;
return;
}
while (number > 0)
{
buffer[i++] = (number % 10) + '0';
number /= 10;
}

for (j = i - 1; j >= 0; j--)
{
if (*index == 1024)
{
write(1, bufferr, *index);
*index = 0;
}
bufferr[*index] =buffer[j];
(*index)++;
*totalb += 1;
}

}





void PrintOctal (va_list *args, int *totalb, char *bufferr ,int *index)
{

         int i = 0, j;
  unsigned int number = va_arg(*args, unsigned int);
  char buffer[BUF_SIZE];

  if (*index == 1024)
  {
  write(1, bufferr, *index);
  *index = 0;
  }
 if (number == 0)
 {
 bufferr[*index] = '0';
 (*index)++;
 *totalb += 1;
 return;
 }
 while (number > 0)
 {
 buffer[i++] = (number % 8) + '0';
 number /= 8;
 }

 for (j = i - 1; j >= 0; j--)
 {
 if (*index == 1024)
 {
 write(1, bufferr, *index);
 *index = 0;
 }
bufferr[*index] =buffer[j];
 (*index)++;
 *totalb += 1;
 }

 }



void PrintHexCp (va_list *args, int *totalb, char *bufferr ,int *index)
{
int i = 0, j;
unsigned int number = va_arg(*args, unsigned int);
char buffer[BUF_SIZE];
hex sympols[] = {{'A',10},{'B',11},{'C',12},{'D',13},{'E',14},{'F',15},{'\0', 0}};
	
	if (*index == 1024)
	{
write(1, bufferr,*index);
*index = 0;
	}
	if (number == 0)
	{
		bufferr[*index] = '0';
		(*index)++;
		*totalb += 1;
		return;
	}
	while (number > 0)
	{
	if ((number % 16) > 9)
	{
	buffer[i++] = sympols[(number % 16) - 10].letter;
	}
	else 
	{
	buffer[i++] = (number % 16) + '0';
	}
	number /= 16;
	}

for (j = i - 1; j >= 0; j--)
{
if (*index == 1024)
{
write(1, bufferr,*index);
*index = 0;
}
	bufferr[*index] = buffer[j];
	(*index)++;
	*totalb += 1;
}
}
void PrintHexSm (va_list *args, int *totalb, char *bufferr ,int *index)
{
	int i = 0, j;
 unsigned int number = va_arg(*args, unsigned int);
 char buffer[BUF_SIZE];
 hex sympols[] = {{'a',10},{'b',11},{'c',12},{'d',13},{'e',14},{'f',15},{'\0', 0}};

         if (*index == 1024)
         {
 write(1, bufferr,*index);
 *index = 0;
         }
     if (number == 0)
         {
                bufferr[*index] = '0';
                 (*index)++;
                *totalb += 1;
                return;
         }
        while (number > 0)
         {
         if ((number % 16) > 9)
         {
         buffer[i++] = sympols[(number % 16) - 10].letter;
         }
         else
         {
        buffer[i++] = (number % 16) + '0';
         }
       number /= 16;
      }

 for (j = i - 1; j >= 0; j--)
 {
 if (*index == 1024)
 {
 write(1, bufferr,*index);
 *index = 0;
 }
       bufferr[*index] = buffer[j];
      (*index)++;
      *totalb += 1;
 }
 }

