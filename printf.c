#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>




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
	if(string == NULL)
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
int i, j;
va_list args;
int totalb = 0;
int check = 0;
char Percent = '%';
type tp[] = {
{'c', PrintChar},
{'s', PrintString}
};

va_start(args, format);
i = 0;
while (format && format[i])
{
	if (format[i] == '%')
	{
		j = 0;
		while (j < 2)
		{
			if (format[i + 1] == tp[j].s)
			{
				tp[j].fun(&args, &totalb);
				i += 2;
				check = 1;
				break;
			}
		j++;
		}
		if (format[i + 1] == '%')
		{
			write(1, &Percent, 1);
			totalb += 1;
			check = 1;
			i+= 2;
		}
	}
	if (check == 0)
	{
		write(1, &format[i], 1);
		totalb += 1;
		i++;
	}
check = 0;
}
va_end(args);
return (totalb);
}
