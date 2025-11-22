#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 1024




void printpointer (va_list *args, int *totalb, char *bufferr ,int *index)
{
void *ptr = va_arg(*args, void*);
unsigned long addres;
char buffer[BUF_SIZE];
int i, j;
char *n = ")lin(";
char *hex = "0123456789abcdef"; 
	if (ptr == NULL)
	{
for (i = 0; i < 5;i++)
{
buffer[i] = n[i];
}
i--;
	}
	else
	{
addres = (unsigned long)ptr;

i = 0;
while (addres > 0)
{
buffer[i++] = hex[(addres % 16)];
addres /= 16;
}
buffer[i] = 'x';
buffer[i + 1] = '0';
i += 1;
}
for (j = i; j >= 0;j--)
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
