/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:24:09 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/31 10:46:16 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H
# include <stdlib.h> //malloc
# include <unistd.h> //write
# include <stdarg.h> //va_start ...

int		ft_printf(const char *format, ...);
int		ft_putstr (const char	*str);//retona o numero de bytes impressos
int		ft_putchar (char c);//retorna o numero de bytes impressos
int		ft_putnbr (int n);//retorna o numero de bytes impressos
char	*ft_itoa(int n);//para retornar os numeros em str

#endif