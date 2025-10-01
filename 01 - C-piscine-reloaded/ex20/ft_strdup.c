/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:08:52 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/01 02:07:06 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*new_src;
	int		size_src;

	size_src = 0;
	while (src[size_src])
		size_src++;
	new_src = (char *) malloc (sizeof(char) * (size_src + 1));
	size_src = 0;
	while (src[size_src])
	{
		new_src[size_src] = src[size_src];
		size_src++;
	}
	new_src[size_src] = '\0';
	return (new_src);
}
/*#include <stdio.h>

int main() {
    char texto[15] = "Hello world!";
    char *new_texto = ft_strdup(texto);

    printf("%s", new_texto);
    free(new_texto);
    return 0;
}*/
