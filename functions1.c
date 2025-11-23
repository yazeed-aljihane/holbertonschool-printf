#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 1024




void PrintUnsigned(va_list *args, int *totalBytes, char *buffer, int *index)
{
	int i = 0, j;
	unsigned int number = va_arg(*args, unsigned int);
	char buffer_tmp[BUF_SIZE];

	if (*index == 1024)
	{
		write(1, buffer, *index);
		*index = 0;
	}
	if (number == 0)
	{
		buffer[*index] = '0';
		(*index)++;
		*totalBytes += 1;
		return;
	}
	while (number > 0)
	{
	buffer_tmp[i++] = (number % 10) + '0';
	number /= 10;
	}

	for (j = i - 1; j >= 0; j--)
	{
		if (*index == 1024)
		{
			write(1, buffer, *index);
			*index = 0;
		}
		buffer[*index] = buffer_tmp[j];
		(*index)++;
		*totalBytes += 1;
	}

}





void PrintOctal (va_list *args, int *totalBytes, char *buffer, int *index)
{

	int i = 0, j;
	unsigned int number = va_arg(*args, unsigned int);
	char buffer_tmp[BUF_SIZE];

  	if (*index == 1024)
  	{
  		write(1, buffer, *index);
  		*index = 0;
  	}
 	if (number == 0)
 	{
 		buffer[*index] = '0';
 		(*index)++;
		*totalBytes += 1;
 		return;
 	}
 	while (number > 0)
 	{
 		buffer_tmp[i++] = (number % 8) + '0';
 		number /= 8;
 	}

 	for (j = i - 1; j >= 0; j--)
 	{
 		if (*index == 1024)
 		{
 			write(1, buffer, *index);
			*index = 0;
 		}
		buffer[*index] = buffer_tmp[j];
 		(*index)++;
		*totalBytes += 1;
	}

 }



void PrintHexUpper(va_list *args, int *totalBytes, char *buffer, int *index)
{
	int i = 0, j;
	unsigned int number = va_arg(*args, unsigned int);
	char buffer_tmp[BUF_SIZE];
	HexMap sympols[] = {{'A',10},{'B',11},{'C',12},{'D',13},{'E',14},{'F',15},{'\0', 0}};
	
	if (*index == 1024)
	{
		write(1, buffer,*index);
		*index = 0;
	}
	if (number == 0)
	{
		buffer[*index] = '0';
		(*index)++;
		*totalBytes += 1;
		return;
	}
	while (number > 0)
	{
		if ((number % 16) > 9)
		{
			buffer_tmp[i++] = sympols[(number % 16) - 10].letter;
		}
		else 
		{
			buffer_tmp[i++] = (number % 16) + '0';
		}
		number /= 16;
	}

	for (j = i - 1; j >= 0; j--)
	{
		if (*index == 1024)
		{
			write(1, buffer,*index);
			*index = 0;
		}
	buffer[*index] = buffer_tmp[j];
	(*index)++;
	*totalBytes += 1;
	}
}


void PrintHexLower(va_list *args, int *totalBytes, char *buffer, int *index)
{
	int i = 0, j;
	unsigned int number = va_arg(*args, unsigned int);
	char buffer_tmp[BUF_SIZE];
	HexMap sympols[] = {{'a',10},{'b',11},{'c',12},{'d',13},{'e',14},{'f',15},{'\0', 0}};

	if (*index == 1024)
	{
 		write(1, buffer,*index);
 		*index = 0;
	}
	if (number == 0)
	{
		buffer[*index] = '0';
		(*index)++;
		*totalBytes += 1;
		return;
	}
	while (number > 0)
	{
		if ((number % 16) > 9)
		{
			buffer_tmp[i++] = sympols[(number % 16) - 10].letter;
		}
		else
		{
			buffer_tmp[i++] = (number % 16) + '0';
	}
	number /= 16;
	}

	for (j = i - 1; j >= 0; j--)
	{
		if (*index == 1024)
		{
		write(1, buffer,*index);
		*index = 0;
		}
		buffer[*index] = buffer_tmp[j];
		(*index)++;
		*totalBytes += 1;
 	}
 }

void PrintNonPrintable(va_list *args, int *totalBytes, char *buffer ,int *index)
{
	int i,j;
	char *string = va_arg(*args,char*);
	char buffer_tmp[BUF_SIZE];
	unsigned int tmp = 0;
	char *hex = "0123456789ABCDEF";

	for (i = 0; string[i]; i++)
	{
		if (*index == 1024)
		{
			write(1, buffer,*index);
			*index = 0;
		}
		if ( (string[i] > 0 && string[i] < 32) || string[i] >= 127)
		{
			tmp = (unsigned char)string[i];
			buffer_tmp[0] = '\\';
			buffer_tmp[1] = 'x';
			buffer_tmp[2] = hex[tmp / 16];
			buffer_tmp[3] = hex[(tmp % 16)];


			for (j = 0; j < 4; j++)
			{
				if (*index == 1024)
				{
					write(1, buffer,*index);
					*index = 0;
				}
				buffer[*index] = buffer_tmp[j];
				(*index)++;
				*totalBytes +=1;
			}
		}
		else
		{
			buffer[*index] = string[i];
			(*index)++;
			*totalBytes += 1;
		}
	}
}
