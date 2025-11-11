/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:02:14 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/07 12:44:26 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	cont_dst;
	size_t	cont_src;

	cont_src = ft_strlen(src);
	cont_dst = ft_strlen(dst);
	if (dsize <= cont_dst)
		return (cont_src + dsize);
	i = 0;
	while ((cont_dst + i) < (dsize - 1) && src[i])
	{
		dst[cont_dst + i] = src[i];
		i++;
	}
	dst[cont_dst + i] = '\0';
	return (cont_dst + cont_src);
}
