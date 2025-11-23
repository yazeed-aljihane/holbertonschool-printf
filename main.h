#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * struct FormatType - Structure to map format specifiers to functions
 * @specifier: The format specifier character (e.g., 'c', 's')
 * @func: Pointer to the function that handles this specifier
 *
 * Description: Maps a format character to its corresponding printing function.
 */
typedef struct FormatType
{
	char specifier;
	void (*func)(va_list *, int *, char *, int *);
} FormatType;

/**
 * struct HexMap - Structure to map integer values to hex characters
 * @letter: The hexadecimal character (e.g., 'A', 'f')
 * @value: The integer value associated with the letter
 *
 * Description: Used for mapping values 10-15 to their hex representation.
 */
typedef struct HexMap
{
	char letter;
	int value;
} HexMap;

/* Main Function */

/**
 * _printf - Custom printf function that formats and prints data
 * @format: The format string containing characters and specifiers
 *
 * Description: Iterates through the format string. If a specifier
 * is found, it calls the corresponding helper function from the struct.
 * Return: The total number of bytes printed.
 */
int _printf(const char *format, ...);

/* Helper Functions */

/**
 * PrintChar - Writes a single character to the buffer
 * @args: List of arguments containing the character
 * @totalBytes: Pointer to the total count of printed bytes
 * @buffer: The local buffer holding the string to be printed
 * @index: Pointer to the current index in the buffer
 */
void PrintChar(va_list *args, int *totalBytes, char *buffer, int *index);

/**
 * PrintString - Writes a string to the buffer
 * @args: List of arguments containing the string
 * @totalBytes: Pointer to the total count of printed bytes
 * @buffer: The local buffer holding the string to be printed
 * @index: Pointer to the current index in the buffer
 */
void PrintString(va_list *args, int *totalBytes, char *buffer, int *index);

/**
 * PrintBinary - Converts and writes an unsigned int as binary
 * @args: List of arguments containing the integer
 * @totalBytes: Pointer to the total count of printed bytes
 * @buffer: The local buffer holding the string to be printed
 * @index: Pointer to the current index in the buffer
 */
void PrintBinary(va_list *args, int *totalBytes, char *buffer, int *index);

/**
 * PrintUnsigned - Writes an unsigned decimal integer
 * @args: List of arguments containing the unsigned integer
 * @totalBytes: Pointer to the total count of printed bytes
 * @buffer: The local buffer holding the string to be printed
 * @index: Pointer to the current index in the buffer
 */
void PrintUnsigned(va_list *args, int *totalBytes, char *buffer, int *index);

/**
 * PrintOctal - Converts and writes a number in octal base
 * @args: List of arguments containing the number
 * @totalBytes: Pointer to the total count of printed bytes
 * @buffer: The local buffer holding the string to be printed
 * @index: Pointer to the current index in the buffer
 */
void PrintOctal(va_list *args, int *totalBytes, char *buffer, int *index);

/**
 * PrintHexUpper - Converts and writes a number in uppercase Hexadecimal
 * @args: List of arguments containing the number
 * @totalBytes: Pointer to the total count of printed bytes
 * @buffer: The local buffer holding the string to be printed
 * @index: Pointer to the current index in the buffer
 */
void PrintHexUpper(va_list *args, int *totalBytes, char *buffer, int *index);

/**
 * PrintHexLower - Converts and writes a number in lowercase Hexadecimal
 * @args: List of arguments containing the number
 * @totalBytes: Pointer to the total count of printed bytes
 * @buffer: The local buffer holding the string to be printed
 * @index: Pointer to the current index in the buffer
 */
void PrintHexLower(va_list *args, int *totalBytes, char *buffer, int *index);

/**
 * PrintNonPrintable - Handles non-printable characters (custom %S specifier)
 * @args: List of arguments containing the string
 * @totalBytes: Pointer to the total count of printed bytes
 * @buffer: The local buffer holding the string to be printed
 * @index: Pointer to the current index in the buffer
 */
void PrintNonPrintable(va_list *args, int *totalBytes, char *buffer, int *index);

/**
 * PrintPointer - Prints a memory address in hexadecimal format
 * @args: List of arguments containing the pointer
 * @totalBytes: Pointer to the total count of printed bytes
 * @buffer: The local buffer holding the string to be printed
 * @index: Pointer to the current index in the buffer
 */
void PrintPointer(va_list *args, int *totalBytes, char *buffer, int *index);
/**
 * PrintNumber - Prints a signed integer
 * @args: List of arguments containing the integer
 * @totalBytes: Pointer to the total count of printed bytes
 * @buffer: The local buffer holding the string to be printed
 * @index: Pointer to the current index in the buffer
 */
void PrintNumber(va_list *args, int *totalBytes, char *buffer, int *index);
#endif
