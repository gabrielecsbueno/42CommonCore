/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabde-so <gabde-so@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:26:41 by gabde-so          #+#    #+#             */
/*   Updated: 2025/10/01 02:26:43 by gabde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		write(1, &str[n], 1);
		n++;
	}
}

int	ft_check(int n)
{
	if (n != 2)
	{
		if (n <= 1)
			ft_putstr("File name missing.\n");
		else
			ft_putstr("Too many arguments.\n");
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	ssize_t	size_arq;
	char	str [4096];
	int		ck;

	ck = ft_check(argc);
	if (ck == -1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return (0);
	}
	size_arq = read(fd, str, 4096);
	while (size_arq > 0)
	{
		write(1, str, size_arq);
		size_arq = read(fd, str, 4096);
	}
	close (fd);
	return (0);
}
