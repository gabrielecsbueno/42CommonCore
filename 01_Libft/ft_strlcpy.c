/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:38:00 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/07 11:01:53 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	if (size == 0)
		return (size);
	while (i < (dsize - 1) && i <= size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size);
}
