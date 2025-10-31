/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:23:47 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/31 11:59:42 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

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
	int	n;

	n = 0;
	if (print == 'c')
		n = ft_putchar(va_arg(argument, char));
	else if (print == 's')
		n = ft_putstr(va_arg(argument, char *));
	//else if (print =='p')
		//ft_putponteiro
	else if (print =='d' || print == 'i' || print == 'u')
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
	//else if (print == '%')
		n = ft_putchar('%');
	return (n);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	size_t	i;
	size_t	amount;
	int		size;

	i = 0;
	amount = 0;
	while (format[i]) //verifica quantos %
	{
		if (format[i++] == '%')//se tiver o % ele conta e pula o proximo, poque pode ter o %%
			amount++;
		else
			i++;
	}//aqui ele contou quantos % idependente de quantos estao na regra ou nao
	//mas se tiver no final (hola %)? sim ele contou
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