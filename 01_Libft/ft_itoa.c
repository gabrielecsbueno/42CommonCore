/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:16:10 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/20 16:54:15 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	cont;

	cont = 0;
	if (n == 0)
		cont = 1;
	else
	{
		if (n < 0)
		{
			n = -n;
			cont++;
		}
		while (n > 0)
		{
			n = n / 10;
			cont++;
		}
	}
	return (cont);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		size;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_size(n);
	s = (char *) malloc(size + 1);
	if (s == NULL)
		return (NULL);
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	s[size] = '\0';
	while (size > sign)
	{
		s[--size] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign)
		s[0] = '-';
	return (s);
}
