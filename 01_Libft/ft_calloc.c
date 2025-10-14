/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 00:00:30 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/14 12:51:51 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*s;
	size_t	bytes;

	bytes = nmemb * size;
	s = malloc(bytes);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, bytes);
	return (s);
}
