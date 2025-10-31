/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:46:57 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/31 10:49:22 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h""

int	ft_putchar (char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr (const char	*str)
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

int	ft_putnbr (int n)
{
	char	*str;

	str = ft_itoa(n);
	return (ft_putstr(str));
}
