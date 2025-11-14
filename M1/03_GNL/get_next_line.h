/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:24:02 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/14 17:02:28 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h> //malloc e free
# include <unistd.h> //read

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
void	*ft_realloc(void *str, size_t old_size, size_t new_size);

//char	*ft_join(char *str, char c);//adiciona o c no final da str e free na str

#endif