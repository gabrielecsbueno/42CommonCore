/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:46:57 by gabde-so          #+#    #+#             */
/*   Updated: 2025/11/05 14:23:40 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(const char	*str)
{
	int		i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)//nao sei se precisa fazer o int max int min, testar sem
{
	int		size;

	size = 0;
	if (n >= 0 && n <= 9)
		size += ft_putchar(n + '0');
	else if (n > 9)
	{
		size += ft_putnbr(n / 10);
		size += ft_putnbr(n % 10);
	}
	else if (n < 0)
	{
		size += ft_putchar('-');
		size += ft_putnbr(n * -1);
	}
	return (size);
}

int	ft_putunsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n <= 9)
		size += ft_putchar(n + '0');
	else if (n > 9)
	{
		size += ft_putunsigned(n / 10);
		size += ft_putunsigned(n % 10);
	}
	return (size);
}

/*
int	ft_puthexa(unsigned long n, char type)
{
	int	size;

	size = 0;
    if (n == 0)
        return (ft_putchar('0'));
    if (n >= 16)
        size += ft_puthexa((n / 16), type);
    if ((n % 16) < 10)
        size += ft_putchar('0' + (n % 16));
    else
	{
		if (type == 'X')
        	size += ft_putchar((n % 16) + 65);
		else
        	size += ft_putchar((n % 16) + 87);
	}
    return (size);
}
*/
int	ft_puthexa(unsigned long n, char type)//tem que devolver um size
{//tavez aqui seria bom receber um tipo, porque eu to usando para %p, %x e %X
	int	size;

	size = 0;
	if (type == 'p')
	{
		if (!n)
			return (ft_putstr("(nil)"));
		size += ft_putstr("0x");
		size += ft_puthexa (n, 'x');
	}
	else if (n >= 16)//se ele é menor ou = a 16 ele entra aqui
	{
		size += ft_puthexa (n / 16, type);//ele volta para a funcao com o n dividido por 16
		//eu realmente fiz mas nao sei o porque do size
		size += ft_puthexa (n % 16, type);//nao sei, seria bom testar
	}
	else//se ele é menor que 16
	{
		if (n >= 10)//ele ve se esta entre 10 e 15
		{
			if (type == 'X')
				size += ft_putchar(n + 55);
			else
				size += ft_putchar(n + 87);//passa por parametro +87 da ascii
		}
		else
			size += ft_putchar('0' + n);//se nao ele so passa o que tem que imprimir
	}
	return (size);//aqui ele retorna quantar vezes ele passou no putchar
}
