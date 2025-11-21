#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>



/**
 * _printf - Custom printf function supporting %c and %s
 * @format: Format string
 *
 * Handles format specifiers by calling the appropriate helper functions.
 * Returns the total number of bytes printed.
 *
 * Return: Total number of bytes printed
 */
int _printf(const char *format, ...);

/**
 * struct type - Structure to map format specifiers to functions
 * @s: Format specifier character
 * @fun: Pointer to the function that handles this specifier
 *
 * This structure is used to associate a format specifier like 'c' or 's'
 * with the corresponding printing function.
 */
typedef struct type
{
char s;
void (*fun)(va_list*, int*);
} type;

/**
 * PrintChar - Prints a single character from a va_list
 * @args: Pointer to the va_list containing the character
 * @totalb: Pointer to an integer counting total bytes printed
 */
void PrintChar(va_list *args, int *totalb);

/**
 * PrintString - Prints a string from a va_list
 * @args: Pointer to the va_list containing the string
 * @totalb: Pointer to an integer counting total bytes printed
 */
void PrintString(va_list *args, int *totalb);

void PrintBinary(va_list *args, int *totalb);

void PrintUdecmile(va_list *args, int *totalb);

void PrintOctal (va_list *args, int *totalb);

void PrintHexCp (va_list *args, int *totalb);

void PrintHexSm (va_list *args, int *totalb);

typedef struct hex
{
char letter;
int number;
}hex;

#endif
