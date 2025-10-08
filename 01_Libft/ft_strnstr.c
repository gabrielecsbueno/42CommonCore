/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:10:52 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/07 22:07:15 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_cont;
	size_t	n;

	l_cont = ft_strlen(little);
	i = 0;
	while (*big && *little && i < len)
	{
		n = 0;
		while (big[i + n] == little[n] && n < l_cont && (i + n) < len)
			n++;
		if (n == l_cont)
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
