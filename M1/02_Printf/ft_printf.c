/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:23:47 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/06 13:16:04 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	ft_type(char format);
static int	ft_printtype(char print, va_list argument);

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	size_t	i;
	int		size;

	if (!format)
		return (-1);
	va_start (arguments, format);
	i = 0;
	size = 0;
	while (format[i])
	{
		if (format[i] != '%')
			size += ft_putchar(format[i]);
		else if (format[i] == '%' && ft_type(format[i + 1]) == 0)
		{
			va_end(arguments);
			return (-1);
		}
		else
			size += ft_printtype(format[++i], arguments);
		i++;
	}
	va_end(arguments);
	return (size);
}

static int	ft_type(char format)
{
	if (format == 'c' || format == 's' || format == 'p' || format == 'd'
		|| format == 'i' || format == 'u' || format == 'x' || format == 'X'
		|| format == '%')
	{
		return (1);
	}
	return (0);
}

static int	ft_printtype(char print, va_list argument)
{
	int	n;

	n = 0;
	if (print == 'c')
		n = ft_putchar((char)va_arg(argument, int));
	else if (print == 's')
		n = ft_putstr(va_arg(argument, char *));
	else if (print == 'd' || print == 'i')
		n = ft_putnbr(va_arg(argument, int));
	else if (print == 'u')
		n = ft_putunsigned(va_arg(argument, unsigned int));
	else if (print == 'p')
		n = ft_puthexa((unsigned long)va_arg(argument, void *), print);
	else if (print == 'x' || print == 'X')
		n = ft_puthexa((unsigned int)va_arg(argument, int), print);
	else if (print == '%')
		n = ft_putchar('%');
	return (n);
}
