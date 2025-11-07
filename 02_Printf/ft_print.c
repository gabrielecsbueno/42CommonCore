/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:46:57 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/06 14:11:55 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(const char	*str)
{
	int		i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		size;

	size = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n >= 0 && n <= 9)
		size += ft_putchar(n + '0');
	else if (n > 9)
	{
		size += ft_putnbr(n / 10);
		size += ft_putnbr(n % 10);
	}
	else if (n < 0)
	{
		size += ft_putchar('-');
		size += ft_putnbr(n * -1);
	}
	return (size);
}

int	ft_putunsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n <= 9)
		size += ft_putchar(n + '0');
	else if (n > 9)
	{
		size += ft_putunsigned(n / 10);
		size += ft_putunsigned(n % 10);
	}
	return (size);
}

int	ft_puthexa(unsigned long n, char type)
{
	int	size;

	size = 0;
	if (type == 'p')
	{
		if (!n)
			return (ft_putstr("(nil)"));
		size += ft_putstr("0x");
		type = 'x';
	}
	if (n >= 16)
		size += ft_puthexa (n / 16, type) + ft_puthexa (n % 16, type);
	else
	{
		if (n >= 10)
		{
			if (type == 'X')
				size += ft_putchar(n + 55);
			else
				size += ft_putchar(n + 87);
		}
		else
			size += ft_putchar('0' + n);
	}
	return (size);
}
