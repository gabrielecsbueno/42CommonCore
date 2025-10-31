/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:16:10 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/31 10:46:27 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Esta funcao é da libft, quando for implementar o printf na lib lembrar da compatibilidade
*/

#include "includes.h"

static char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(s);
	dest = (char *) malloc (sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, size);
	dest[size] = '\0';
	return (dest);
}

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
