/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:23:47 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/30 13:01:13 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	ft_print(const char	*text)
{
	int		i;

	i = 0;
	while (text[i])
	{
		write (1, &text[i], 1);
		i++;
	}
	return (i);
}

static int	ft_type (char	*format)
{
	int	i;
	int	type;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i+1] == 'c')
			return(type = 1);
		else if (format[i] == '%' && format[i+1] == 's')
			return(type = 2);
		else if (format[i] == '%' && format[i+1] == 'p')
			return(type = 3);
		else if (format[i] == '%' && format[i+1] == 'd')
			return(type = 4);
		else if (format[i] == '%' && format[i+1] == 'i')
			return(type = 5);
		else if (format[i] == '%' && format[i+1] == 'u')
			return(type = 6);
		else if (format[i] == '%' && format[i+1] == 'x')
			return(type = 7);
		else if (format[i] == '%' && format[i+1] == 'X')
			return(type = 8);
		else if (format[i] == '%' && format[i+1] == '%')
			return(type = 9);
		else if (format[i] == '%')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	size_t	i;
	size_t	amount;
	int		size;
	int		type;

	i = 0;
	amount = 0;
	while (format[i]) //verifica quantos argumentos tem na str
	{
		if(format[i] == '%' && (format[i+1] == 'c' || format[i+1] == 's' || format[i+1] == 'p' || format[i+1] == 'd' || format[i+1] == 'i' || format[i+1] == 'u' || format[i+1] == 'x' || format[i+1] == 'X' || format[i+1] == '%'))
			amount++;
		i++;
	}
	if (amount == 0 && *format) //se nao tiver argumentos e tiver coisas para imprimir no forma
		return (ft_print(format));
	va_start (arguments, amount);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
			ft_type(format[i]);
	}
	type = 0;
}