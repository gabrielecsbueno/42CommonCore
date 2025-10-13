/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:23:19 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/13 12:57:44 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	s_s1;
	size_t	s_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	dest = (char *) malloc (s_s1 + s_s2 + 1);

}
