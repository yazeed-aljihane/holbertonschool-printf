#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 33



/**
 * PrintChar - Prints a single character from a va_list
 * @args: Pointer to the va_list containing the character
 * @totalb: Pointer to an integer counting total bytes printed
 *
 * Extracts the next argument as an int, writes it as a character
 * to standard output, and increments totalb by 1.
 */
void PrintChar(va_list *args, int *totalb)
{
	char c  = va_arg(*args, int);

	write(1, &c, 1);
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
void PrintString(va_list *args, int *totalb)
{
	char *string = va_arg(*args, char*);
	char *n = "(null)";
	int length;

	if (string == NULL)
	{
	write(1, n, strlen(n));
	*totalb += strlen(n);
	}
	else
	{
	length = strlen(string);
	write(1, string, length);
	*totalb += length;
	}
}

void PrintNumber(va_list *args, int *totalb)
{
int n = va_arg(*args, int);
char buffer[BUF_SIZE];
int length;

length = snprintf(buffer, BUF_SIZE, "%d", n);
if (length > 0)
{
write(1, buffer, length);
*totalb += length;
}
}

void PrintBinary(va_list *args, int *totalb)
{
int i = 0, j;
unsigned int number = va_arg(*args, unsigned int);
char buffer[BUF_SIZE];
if (number == 0)
{
write(1, "0", 1);
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
write(1, &buffer[j], 1);
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
type tp[] = {{'c', PrintChar}, {'s', PrintString}, {'i', PrintNumber}, {'d', PrintNumber}, {'b', PrintBinary},{'u', PrintUdecmile},
{'o', PrintOctal},{'X', PrintHexCp}, {'x', PrintHexSm} ,{'\0', NULL}};

if (format == NULL)
	return (-1);
va_start(args, format);
for (i = 0; format && format[i]; i++)
{
	if (format[i] == '%')
	{
	if (format[i + 1] == '\0')
	{
	va_end(args);
	return (-1);
	}
	if (format[i + 1] == '%')
	{
		write(1, &Percent, 1);
		totalb += 1;
		i++;
		continue;
	}
		j = 0;
		while (tp[j].s != '\0')
		{
			if (format[i + 1] == tp[j].s)
			{
				tp[j].fun(&args, &totalb);
				i++;
				check = 1;
				break;
			}

		j++;
		}
	if (check == 0)
	{
	write(1, &format[i], 1);
	write(1, &format[i + 1], 1);
	totalb += 2;
	i++;
	}
	check = 0;
}
else
{
write(1, &format[i], 1);
totalb += 1;
}
}
va_end(args);
return (totalb);
}
