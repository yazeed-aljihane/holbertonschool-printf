#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 1024



/**
 * PrintChar - Prints a single character from a va_list
 * @args: Pointer to the va_list containing the character
 * @totalb: Pointer to an integer counting total bytes printed
 *
 * Extracts the next argument as an int, writes it as a character
 * to standard output, and increments totalb by 1.
 */
void PrintChar(va_list *args, int *totalb, char *buffer ,int *index)
{
	char c  = va_arg(*args, int);
if (*index == 1024)
{
write(1,buffer,*index);
*index = 0;
}
	buffer[*index] = c;
	(*index)++;
	*totalb += 1;
}

/**
 * PrintString - Prints a string from a va_list
 * @args: Pointer to the va_list containing the string
 * @totalb: Pointer to an integer counting total bytes printed
 *
 * Extracts the next argument as a string, writes it to standard output,
 * and increments totalb by the string length.
 */
void PrintString(va_list *args, int *totalb, char *buffer ,int *index)
{
	
unsigned int i;
	char *string = va_arg(*args, char*);
	char *n = "(null)";

if (*index == 1024)
           {
           write(1,buffer,*index);
           *index = 0;
           }
	if (string == NULL)
	{
	for (i = 0; i < strlen(n);i++)
	{
		if (*index == 1024)
		{
		write(1,buffer,*index);
		*index = 0;
		}
		buffer[*index] = n[i];
		(*index)++;
		*totalb += 1;
		}
	}
	else
	{

for (i = 0; i < strlen(string);i++)
{
if (*index == 1024)
{
write(1,buffer,*index);
*index = 0;
}
buffer[*index] = string[i];
(*index)++;
*totalb += 1;
}
}
}

	


void PrintNumber(va_list *args, int *totalb, char *bufferr ,int *index)
{
int i = 0, j;
int number = va_arg(*args, int);
char buffer[BUF_SIZE];
unsigned int abs;
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
if (number < 0)
{
if (*index == 1024)
{
write(1, bufferr,*index);
*index = 0;
}
bufferr[*index] = '-';
(*index)++;
*totalb += 1;
abs = -number;
}
else
{
abs = number;
}
while (abs > 0)
{
buffer[i++] = (abs % 10) + '0';
abs /= 10;
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

void PrintBinary(va_list *args, int *totalb, char *bufferr ,int *index)
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
buffer[i++] = (number % 2) + '0';
number /= 2;
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

/**
 * _printf - Custom printf function supporting %c and %s
 * @format: Format string
 *
 * Handles %c and %s format specifiers by calling appropriate
 * helper functions. Prints the formatted output to standard output
 * and returns the total number of bytes printed.
 *
 * Return: Total number of bytes printed
 */
int _printf(const char *format, ...)
{
int i, j, totalb = 0, check = 0;
va_list args;
char Percent = '%';
char buffer[BUF_SIZE];
int index = 0;

type tp[] = {{'c', PrintChar}, {'s', PrintString}, {'i', PrintNumber}, {'d', PrintNumber}, {'b', PrintBinary},{'u', PrintUdecmile},
{'o', PrintOctal},{'X', PrintHexCp}, {'x', PrintHexSm} ,{'S', PrintNon},{'\0', NULL}};

if (format == NULL)
	return (-1);
va_start(args, format);
for (i = 0; format && format[i]; i++)
{
	if (index == 1024)
	{
		write(1,buffer,index);
		index = 0;
	}
	if (format[i] == '%')
	{
	if (format[i + 1] == '\0')
	{
	va_end(args);
	return (-1);
	}
	if (format[i + 1] == '%')
	{
		buffer[index++] = Percent;
		totalb += 1;
		i++;
		continue;
	}
		j = 0;
		while (tp[j].s != '\0')
		{
			if (format[i + 1] == tp[j].s)
			{
				tp[j].fun(&args, &totalb,buffer,&index);
				i++;
				check = 1;
				break;
			}

		j++;
		}
	if (check == 0)
{
if (index == 1023)
{
write(1,buffer,index);
index = 0;
}
	buffer[index++] = format[i];
	buffer[index++] = format[i + 1];
	totalb += 2;
	i++;
	}
	check = 0;
}
else
{
buffer[index++] = format[i];
totalb += 1;
}
}
if (index > 0)
write(1,buffer,index);

va_end(args);
return (totalb);
}
