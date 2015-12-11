/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:31:27 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/11 19:36:26 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more.h"

static void		ft_recursiv_check(int size, char tab[size][5], int i, int j)
{
	if (tab[i][j + 1] == '#')
		ft_recursiv_check(size, tab, i, j + 1);
	if (tab[i + 1][j] == '#')
		ft_recursiv_check(size, tab, i + 1, j);
	else
		ft_print_error();
}

static void		ft_check_block(int size, char tab[size][5], int i, int j)
{
	while (i % 4 != 0 || i == 0)
	{
		while (tab[i][j] != '#' && tab[i][j] != '\0')
			j++;
		if (tab[i][j] == '#')
			ft_recursiv_check(size, tab, i, j);
		j = 0;
		i++;
	}
	ft_print_error();
}

static void		ft_check_map(int ret, char *buf)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	if ((ret + 1) % 21 != 0)
		ft_print_error();
	while (buf[i])
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			ft_print_error();
		if (buf[i] == '\n' && (i + 1) % 21 == 0)
			j--;
		else if (buf[i] == '\n' && (i + j) % 5 != 0)
			ft_print_error();
		i++;
	}
}

static void		ft_char_to_tab(int size, char *buf)
{
	int		i;
	int		j;
	int		k;
	char	tab[size][5];

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (j < 4)
		{
			tab[i][j++] = buf[k++];
		}
		tab[i][j] = '\0';
		k++;
		if (buf[k] == '\n' && buf[k] != '\0')
			k++;
		i++;
	}
	i = 0;
	j = 0;
	ft_check_block(size, tab, i, j);
}

int				main(int ac, char **av)
{
	int		fd;
	int		ret;
	int		size;
	char	buf[1024];

	if (ac != 2)
		ft_print_error();
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_print_error();
	if ((ret = read(fd, buf, 1020)) == -1)
		ft_print_error();
	if ((close(fd)) == -1)
		ft_print_error();
	buf[ret] = '\0';
	ft_check_map(ret, buf);
	size = 4 * ((ret + 1) / 21);
	ft_char_to_tab(size, buf);
}
