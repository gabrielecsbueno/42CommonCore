/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:05:40 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/01 01:57:52 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else if (nb > 1)
	{
		nb = nb * ft_recursive_factorial (nb - 1);
	}
	return (nb);
}
/*#include <stdio.h>

int main() {
    int nb = 0;

    int factorial = ft_recursive_factorial(nb);
    printf("O fatorial de %d = %d", nb, factorial);
    return 0;
}*/
