/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 08:48:31 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/09 12:17:20 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*byte_s;
	size_t			i;

	byte_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		byte_s[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
