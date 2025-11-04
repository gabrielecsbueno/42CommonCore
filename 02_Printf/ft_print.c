/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:46:57 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/04 09:46:01 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(const char	*str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	if(!str)
		return(-1);
	return (i);
}

int	ft_putnbr(int n)
{
	char	*str;

	str = ft_itoa(n);
	return (ft_putstr(str));
}

/*
int	ft_puthex(unsigned long n)
{
	int	size;
	
	size = ft_putstr("0x");
	while (n > 0)
	{
		if ((n % 16) >= 10)
			size = size + ft_putchar((n % 16) + 87);
		else
			size = size + ft_putchar('0' + (n % 16));
		n = n / 16;
	}
	return (size);
}
*/

int	ft_puthex(unsigned long n, int size)//tem que devolver um size
{
	if (n >= 16)
	{
		size = ft_puthex (n / 16, size);
		size = ft_puthex (n % 16, size);
	}
	else
	{
		if (n >= 10)
			size = size + ft_putchar(n + 87);
		else
			size = size + ft_putchar('0' + n);
	}
	return (size);
}
