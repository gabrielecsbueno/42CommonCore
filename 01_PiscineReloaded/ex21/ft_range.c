/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:33:53 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/01 02:18:48 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*srcn;
	int	i;
	int	size;

	if (min >= max)
		return (NULL);
	size = max - min;
	srcn = (int *) malloc (sizeof(int) * size);
	if (!srcn)
		return (NULL);
	i = 0;
	while (i < size)
	{
		srcn[i] = min + i;
		i++;
	}
	return (srcn);
}
/*#include <stdio.h>
int main(void)
{
	int *num;
	int min = 9;
	int max = 15;
	int size = max - min;
	int i;

	num = ft_range(min, max);
	if (num == NULL)
	{
		printf("Numero minimo maior ou igual ao maximo\n");
		return (0);
	}
	i = 0;
	while (i < size)
	{
		printf("%d, ", num[i]);
		i++;
	}
	printf("\n");
	free(num);
	return (0);
}*/
