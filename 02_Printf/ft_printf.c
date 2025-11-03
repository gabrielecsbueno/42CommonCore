/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:23:47 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/04 00:04:30 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

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
	else if (print =='p')
		n = ft_puthex((unsigned long)va_arg(argument, void *));
	else if (print == 'd' || print == 'i' || print == 'u')
	{
		n = va_arg(argument, int);
		if (print == 'u' && n < 0)
			n = ft_putnbr(n * -1);
		else
			n = ft_putnbr(n);
	}
	//else if (print == 'x')
		//ft_putint
	//else if (print == 'X')
		//ft_putint
	else if (print == '%')
		n = ft_putchar('%');
	return (n);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	size_t	i;
	int		size;

	va_start (arguments, format);//inicia os argumentos com a quantidade encontrada
	i = 0;
	size = 0;
	while (format[i])//inicia a impressao
	{
		if (format[i] == '%' && ft_type (format[i + 1]) == 0)
		{
			va_end(arguments);
			return(-1);
		}
		if (format[i] != '%')//se nao for a regra ele imprime
			size += ft_putchar(format[i]);
		else//se encontrar o % precisa saber qual regra é
		{
			i++;//passa para o priximo caractere, o que define a regra
			size += ft_printtype(format[i], arguments);//soma o tamanho retornado
		}
		i++;
	}
	va_end(arguments);
	return (size);
}