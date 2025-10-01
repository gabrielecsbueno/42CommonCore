/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:01:18 by gabde-so          #+#    #+#             */
/*   Updated: 2025/09/26 11:01:39 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	x;

	x = *a;
	*a = *b;
	*b = x;
}
/*
#include <stdio.h>
int main()
{
    int n1 = 1;
    int n2 = 2;
    
    printf ("valor inicial de n1 = %d \n", n1);
    printf ("valor inicial de n2 = %d \n\n", n2);

    ft_swap(&n1, &n2);
    
    printf ("valor alterado de n1 = %d \n", n1);
    printf ("valor alterado de n2 = %d \n", n2);

    return 0;
}
*/
