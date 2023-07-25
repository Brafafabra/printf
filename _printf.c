#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used
 * to end output to strings).
 */
int _printf(const char *format, ...)
{
	int chars_printed = 0;
	int temp;
	int divisor;
	int i;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Move past the '%' */
			if (*format == '\0') /* Check for the end of the format string */
				break;

			/* Handle the conversion specifier */
			switch (*format)
			{
				case 'c':
					/* Fetch the next argument of type char and print it */
					_putchar(va_arg(args, int));
					chars_printed++;
					break;

				case 's':
				{
					/* Fetch the next argument of type char* (string) and print it */
					const char *str = va_arg(args, const char *);
					while (*str)
					{
						_putchar(*str);
						str++;
						chars_printed++;
					}
					break;
				}

				case 'd':
				case 'i':
				{
					/* Fetch the next argument of type int and print it */
					int num = va_arg(args, int);
					int num_chars = 0;

					/* Handle negative numbers */
					if (num < 0)
					{
						_putchar('-');
						chars_printed++;
						num = -num;
					}

					/* Calculate the number of digits in the integer */
					temp = num;
					do
					{
						temp /= 10;
						num_chars++;
					} while (temp);

					/* Print each digit in reverse order */
					divisor = 1;
					for (i = 1; i < num_chars; i++)
						divisor *= 10;

					while (divisor)
					{
						int digit = num / divisor;
						_putchar(digit + '0');
						chars_printed++;
						num %= divisor;
						divisor /= 10;
					}

					_putchar(num + '0');
					chars_printed++;
					break;
				}

				case '%':
					/* Handle the %% case (print a single '%') */
					_putchar('%');
					chars_printed++;
					break;

				default:
					/* If the conversion specifier is not recognized, ignore it */
					break;
			}
		}
		else
		{
			/* Regular character, just print it */
			_putchar(*format);
			chars_printed++;
		}

		format++; /* Move to the next character in the format string */
	}

	va_end(args);
	return chars_printed;
}
