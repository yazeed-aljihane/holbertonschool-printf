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
void PrintChar(va_list *args, int *totalBytes, char *buffer, int *index)
{
	char c  = va_arg(*args, int);
	if (*index == 1024)
	{
		write(1, buffer, *index);
		*index = 0;
	}
	buffer[*index] = c;
	(*index)++;
	*totalBytes += 1;
}

/**
 * PrintString - Prints a string from a va_list
 * @args: Pointer to the va_list containing the string
 * @totalb: Pointer to an integer counting total bytes printed
 *
 * Extracts the next argument as a string, writes it to standard output,
 * and increments totalb by the string length.
 */
void PrintString(va_list *args, int *totalBytes, char *buffer, int *index)
{

	unsigned int i;
	char *string = va_arg(*args, char*);
	char *n = "(null)";

	if (*index == 1024)
	{
		write(1, buffer, *index);
		*index = 0;
	}
	if (string == NULL)
	{
		for (i = 0; i < strlen(n); i++)
		{
			if (*index == 1024)
			{
				write(1, buffer, *index);
				*index = 0;
			}
			buffer[*index] = n[i];
			(*index)++;
			*totalBytes += 1;
		}
	}
	else
	{
		for (i = 0; i < strlen(string); i++)
		{
			if (*index == 1024)
			{
				write(1, buffer, *index);
				*index = 0;
			}
			buffer[*index] = string[i];
			(*index)++;
			*totalBytes += 1;
		}
	}
}



void PrintNumber(va_list *args, int *totalBytes, char *buffer, int *index)
{
	int i = 0, j;
	int number = va_arg(*args, int);
	char buffer_tmp[BUF_SIZE];
	unsigned int abs;

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
	if (number < 0)
	{
		if (*index == 1024)
		{
			write(1, buffer, *index);
			*index = 0;
		}
		buffer[*index] = '-';
		(*index)++;
		*totalBytes += 1;
		abs = -number;
	}
	else
	{
		abs = number;
	}
	while (abs > 0)
	{
		buffer_tmp[i++] = (abs % 10) + '0';
		abs /= 10;
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

void PrintBinary(va_list *args, int *totalBytes, char *buffer, int *index)
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
		buffer_tmp[i++] = (number % 2) + '0';
		number /= 2;
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

/**
 * _printf - Custom printf function supporting various format specifiers
 * @format: The format string containing characters and specifiers
 *
 * Description: Manages the buffer and calls helper functions based on
 * the format specifiers found in the string. It handles the logic for
 * matching '%' with the correct function from the struct array.
 *
 * Return: Total number of bytes printed
 */
int _printf(const char *format, ...)
{
	int i, j, totalBytes = 0, found = 0;
	va_list args;
	char buffer[BUF_SIZE];
	int index = 0;
	FormatType types[] = {
		{'c', PrintChar}, {'s', PrintString}, {'i', PrintNumber},
		{'d', PrintNumber}, {'b', PrintBinary}, {'u', PrintUnsigned},
		{'o', PrintOctal}, {'X', PrintHexUpper}, {'x', PrintHexLower},
		{'S', PrintNonPrintable}, {'p', PrintPointer}, {'\0', NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; format && format[i]; i++)
	{
		if (index == 1024)
		{
			write(1, buffer, index);
			index = 0;
		}
		if (format[i] != '%')
		{
			buffer[index++] = format[i];
			totalBytes++;
		}
		else
		{
				if (format[i + 1] == '\0')
				{
					va_end(args);
					if (index > 0)
						write(1, buffer, index);
					return (-1);
				}
				if (format[i + 1] == '%')
				{
					buffer[index++] = '%';
					totalBytes++;
					i++;
				}
				else
				{
					found = 0;
					for (j = 0; types[j].specifier != '\0'; j++)
					{
						if (format[i + 1] == types[j].specifier)
						{
							types[j].func(&args, &totalBytes, buffer ,&index);
							i++;
							found = 1;
							break;
						}

					}
					if (!found)
					{
						if (index >= BUF_SIZE - 1)
						{
						write(1, buffer, index);
						index = 0;
						}
						buffer[index++] = format[i];
						buffer[index++] = format[i + 1];
						totalBytes += 2;
						i++;
					}
				}
			}
		}
		if (index > 0)
			write(1, buffer, index);
		va_end(args);
		return (totalBytes);
}
