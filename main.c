#include <limits.h>
#include <stdio.h>
#include "main.h"
#include <stdlib.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	len = _printf("Hello %c World %s!\n", NULL, NULL);
	printf("\n_ printf returned: %d\n", len);
	_printf("Character:[%c]\n", NULL);
	printf("printf Character:[%c]\n", NULL);
	_printf("String:[%s]\n", NULL);
	printf("printf String:[%s]\n", NULL);
return (0);
}
