/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:24:09 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/05 12:50:53 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H
# include <stdlib.h> //malloc
# include <unistd.h> //write
# include <stdarg.h> //va_start ...

int		ft_printf(const char *format, ...);
int		ft_putstr(const char	*str);//retona o numero de bytes impressos
int		ft_putchar(char c);//retorna o numero de bytes impressos
int		ft_putnbr(int n);//retorna o numero de bytes impressos
int		ft_putunsigned(unsigned int n);//imprime unsigned (0 a 4.294.967.295)
int		ft_puthexa(unsigned long n, char type);

#endif
