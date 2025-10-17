/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:16:10 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/16 11:16:13 by gabde-so         ###   ########.fr       */
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
	int	i;
	int	size;

	size = ft_size(n);
	s = (char *) malloc(size + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		s[i] = '-';
		n = -n;
		i++;
	}
	s[size] = '\0';
	while (i < size)
	{
		size--;
		s[size] = (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}
