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

	len = printf("%");
	printf("\n_ printf returned: %d\n", len);
	_printf("Character:[%c]\n", 'g');
	_printf("NULL Character:[%c]\n", NULL);
	_printf("NULL String:[%s]\n", NULL);
	_printf("String:[%s]\n", "sdffgdfgdfdfgdf");
return (0);
}
