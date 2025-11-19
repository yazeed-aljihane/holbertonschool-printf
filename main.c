#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("Character:[%d]\n", 'H');
    printf("printf Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("printf String:[%s]\n", "I am a string !");
    return (0);
} 
