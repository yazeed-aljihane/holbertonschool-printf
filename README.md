# _printf

A custom implementation of the standard C library function `printf`. This project is part of the **Holberton School** curriculum. It mimics the functionality of the standard `printf` function, writing output to the standard output stream (stdout) with formatting capabilities.

## Description

The `_printf` function writes output to stdout under the control of a `format` string that specifies how subsequent arguments (accessed via `stdarg`) are converted for output.

This implementation uses a **local buffer of 1024 bytes** to minimize calls to `write`, optimizing performance significantly compared to writing character by character.

## Prototype

    int _printf(const char *format, ...);

### Return Value
Returns the **total number of characters printed** (excluding the null byte used to end output to strings). If an error occurs, it returns `-1`.

## Supported Format Specifiers

The function supports the following conversion specifiers:

| Specifier | Description | Example | Output |
| :---: | :--- | :--- | :--- |
| **%c** | Prints a single character. | `_printf("%c", 'H');` | `H` |
| **%s** | Prints a string. | `_printf("%s", "Hello");` | `Hello` |
| **%d** / **%i** | Prints a signed integer (decimal). | `_printf("%d", 1024);` | `1024` |
| **%b** | **(Custom)** Converts unsigned int to Binary. | `_printf("%b", 98);` | `1100010` |
| **%u** | Prints an unsigned integer. | `_printf("%u", 42);` | `42` |
| **%o** | Prints an unsigned integer in Octal. | `_printf("%o", 80);` | `120` |
| **%x** | Prints an unsigned int in Hexadecimal (Lower). | `_printf("%x", 255);` | `ff` |
| **%X** | Prints an unsigned int in Hexadecimal (Upper). | `_printf("%X", 255);` | `FF` |
| **%S** | **(Custom)** Prints string with non-printable chars as `\xHH`. | `_printf("%S\n", "Holberton\nSchool");` | `Holberton\x0ASchool` |
| **%p** | Prints a pointer address (memory address). | `_printf("%p", (void *)ptr);` | `0x7ffe637541f0` |
| **%%** | Prints a literal percent sign. | `_printf("100%%");` | `100%` |

## File Structure

| File | Description |
| :--- | :--- |
| `main.h` | Header file containing all function prototypes and struct definitions. |
| `_printf.c` | Contains the main `_printf` function and logic for parsing format specifiers. |
| `functions.c` | Contains helper functions for printing numbers and specialized conversions. |
| `man_3_printf` | Custom Man Page for the function. |

## Compilation

The code is designed to compile on Ubuntu 20.04 LTS using `gcc`.

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf

## Usage Example

    #include "main.h"

    int main(void)
    {
        int len;

        len = _printf("Let's try to printf a simple sentence.\n");
        _printf("Length: %d\n", len);
    
        _printf("Negative: %d\n", -762534);
        _printf("Binary: %b\n", 98);
        _printf("String with non-printables: %S\n", "Best\nSchool");

        return (0);
    }

## Authors

* **[Yazeed Aljohani]** - [Github Profile](https://github.com/YourUsername)
* **[Partner Name]** - [Github Profile](https://github.com/PartnerUsername)
