/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:24:09 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/06 10:49:13 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H
# include <unistd.h> //write
# include <stdarg.h> //va_start ...

int		ft_printf(const char *format, ...);
int		ft_putstr(const char *str);
int		ft_putchar(char c);
int		ft_putnbr(int n); //imprime int - de -2147483648 a 2147483647
int		ft_putunsigned(unsigned int n);//imprime unsigned - de 0 a 4.294.967.295
int		ft_puthexa(unsigned long n, char type);

#endif
