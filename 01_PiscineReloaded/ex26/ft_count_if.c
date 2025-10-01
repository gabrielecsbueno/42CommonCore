/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:23:28 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/01 02:23:31 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*));

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) == 1)
			c++;
		i++;
	}
	return (c);
}

/*
#include <stdio.h>

int	ft_count_a(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == 'a')
			return (1);
		i++;
	}
	return(0);
}

int	main(void)
{
	char	*text[] = {"ola", "mundo", "42", 0};
	int	ret;

	ret = ft_count_if(text, &ft_count_a);

	printf("retornou %d", ret);
	return (0);
}
*/
