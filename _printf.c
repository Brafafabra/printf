#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used
 * to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int chars_printed = 0;

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
				putchar(va_arg(args, int));
				chars_printed++;
				break;

			case 's':
			{
				/* Fetch the next argument of type char* (string) and print it */
				const char *str = va_arg(args, const char *);
				while (*str)
				{
					putchar(*str);
					str++;
					chars_printed++;
				}
				break;
			}

			case '%':
				/* Handle the %% case (print a single '%') */
				putchar('%');
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
			putchar(*format);
			chars_printed++;
		}

		format++; /* Move to the next character in the format string */
	}

	va_end(args);
	return chars_printed;
}
