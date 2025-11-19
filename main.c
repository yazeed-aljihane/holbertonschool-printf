#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;

	len = _printf("Hello %c World %s!\n", 'f', "sdfsdfsdfsd");
	printf("_printf returned: %d\n\n", len);
	_printf("Character:[%c]\n", 'g');
	_printf("Percent: %%\n");
	_printf("NULL Character:[%c]\n", NULL);
	_printf("NULL String:[%s]\n", NULL);
	_printf("String:[%s]\n", "sdffgdfgdfdfgdf");
	_printf("Empty: [%s]\n", "");

	return (0);
}
