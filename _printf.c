#include <stdio.h>
#include <stdarg.h>

/**
* _printf - produces output according to a format
* @format: character string
* Return: number of characters printed excluding null byte
*/

int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int printed = 0;

while (*format)
return (printed);
}
