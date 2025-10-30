/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:23:47 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/30 22:54:41 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	ft_putstr (const char	*str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

static	int	ft_putchar (char c)
{
	write (1, &c, 1);
	return (1);
}

static int	ft_type (char	format)
{
	if (format == 'c')
		return(1);
	else if (format == 's')
		return(2);
	else if (format =='p')
		return(3);
	else if (format =='d')
		return(4);
	else if (format == 'i')
		return(5);
	else if (format == 'u')
		return(6);
	else if (format == 'x')
		return(7);
	else if (format == 'X')
		return(8);
	else if (format == '%')
		return(9);
	return (-1);
}

static int	ft_printtype (char	print, va_list argument)
{
	int	size;

	size = 0;
	if (print == 'c')
		size = ft_putchar(va_arg(argument, char));
	else if (print == 's')
		size = ft_putstr(va_arg(argument, char *));
	else if (print =='p')
		//ft_putptr
	else if (print =='d')
		//ft_putint
	else if (print == 'i')
		//ft_putint
	else if (print == 'u')
		//ft_putint
	else if (print == 'x')
		//ft_putint
	else if (print == 'X')
		//ft_putint
	else if (print == '%')
		//ft_putint
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	size_t	i;
	size_t	amount;
	int		size;

	i = 0;
	amount = 0;
	while (format[i]) //verifica quantos argumentos tem na str
	{
		if (format[i] == '%')//se tiver o % obrigatoriamente tem que conter uma das regras
		{
			i++;
			if (ft_type(format[i]) == -1)//se nao tiver nas regras ele sai
				return (-1);
			amount++;//se nao ele conta
		}
		i++;
	}
	if (amount == 0 && *format) //se nao tiver argumentos e tiver coisas para imprimir no forma
		return (ft_putstr(format));
	va_start (arguments, amount);//inicia os argumentos com a quantidade encontrada
	i = 0;
	size = 0;
	while (format[i])//inicia a impressao
	{
		if (format[i] != '%')//se nao for a regra ele imprime
			size += ft_putchar(format[i]);
		else//se encontrar o % precisa saber qual regra é
		{
			i++;//passa para o priximo caractere, o que define a regra
			size += ft_printtype(format[i], arguments);//soma o tamanho retornado
		}
		i++;
	}
	return (size);
}