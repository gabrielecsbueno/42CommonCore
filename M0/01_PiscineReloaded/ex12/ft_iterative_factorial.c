/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:03:17 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/01 01:55:35 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	factorial;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	factorial = 1;
	while (nb > 1)
	{
		factorial = factorial * nb;
		nb--;
	}
	return (factorial);
}
/*#include <stdio.h>

int main() {
    int nb = 7;

    int factorial = ft_iterative_factorial(nb);
    printf("O fatorial de %d = %d", nb, factorial);
    return 0;
}*/
