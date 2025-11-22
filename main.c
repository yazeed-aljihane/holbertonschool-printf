#include "main.h"
#include <stdio.h>
#include <limits.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
int x = 5;

_printf("%b", 1024);
_printf("There is %b bytes in %b KB\n", 1024, 1);
_printf("Negative:[%d]\n", -762534);
_printf("Character:[%c]\n", 'H');
_printf("String:[%s]\n", "I am a string !");
printf("String:[%s]\n", "I am a string !");
 _printf("%S\n", "Best\nSchool");
 _printf("pointer: %p\n", &x);
return (0);
}
