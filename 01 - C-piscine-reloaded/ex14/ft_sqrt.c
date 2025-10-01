/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:07:17 by gabde-so          #+#    #+#             */
/*   Updated: 2025/09/26 11:08:14 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sr;

	sr = 1;
	while ((sr * sr) < nb)
		sr++;
	if ((sr * sr) != nb)
		return (0);
	else
		return (sr);
}
/*
#include <stdio.h>
int	main()
{
	int r;

	r = ft_sqrt(16);

	printf("%d", r);
	return (0);
}
*/
