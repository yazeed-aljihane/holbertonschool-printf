#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);


typedef struct type {
char s;
void (*fun)(va_list*, int*);
}type;
void PrintChar (va_list *args, int *totalb);
void PrintString(va_list *args, int *totalb);
#endif
