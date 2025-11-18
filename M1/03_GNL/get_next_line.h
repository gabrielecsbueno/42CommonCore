/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:24:02 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/17 15:22:31 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h> //malloc e free
# include <unistd.h> //read

//nao sei se realmente posso fazer isso
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd);

//int	ft_isline(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strindex(const char *s, char c);
//char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
//char	*ft_strjoin(char const *s1, char const *s2);

//void	*ft_realloc(void *str, size_t old_size, size_t new_size);
char	*ft_strjoin(char const *s1, char const *s2);
#endif