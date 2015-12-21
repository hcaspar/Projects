/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:31:27 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/21 12:45:08 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more.h"

static int		ft_recursiv_check(int size, char tab[size][5], t_compt g, int t)
{
	if (tab[g.i][g.j + 1] == '#')
	{
		tab[g.i][g.j + 1] = 'A' + (g.i / 4);
		g.j++;
		t = ft_recursiv_check(size, tab, g, t + 1);
		g.j--;
	}
	if (g.j != 0 && tab[g.i][g.j - 1] == '#')
	{
		tab[g.i][g.j - 1] = 'A' + (g.i / 4);
		g.j--;
		t = ft_recursiv_check(size, tab, g, t + 1);
		g.j++;
	}
	if (tab[g.i + 1][g.j] == '#' && g.i + 1 != (g.i / 4) * 4 + 4)
	{
		tab[g.i + 1][g.j] = 'A' + (g.i / 4);
		g.i++;
		t = ft_recursiv_check(size, tab, g, t + 1);
		g.i--;
	}
	if (t > 4)
		return (0);
	return (t);
}

static void		ft_check_block(int size, char tab[size][5], t_compt g)
{
	int		t;

	t = 0;
	while (t < 4 && g.i < size)
	{
		while (tab[g.i][g.j] != '#' && tab[g.i][g.j] != '\0')
			g.j++;
		if (tab[g.i][g.j] == '#')
		{
			tab[g.i][g.j] = 'A' + (g.i / 4);
			if ((t = ft_recursiv_check(size, tab, g, 1)) != 4)
				ft_print_error();
			t = 0;
			g.i = (g.i / 4) * 4 + 4;
		}
		else
		{
			t++;
			g.i++;
		}
		g.j = 0;
	}
	if (t != 0)
		ft_print_error();
	ft_create_map(size, tab, 2);
}

static void		ft_check_map(int ret, char *buf)
{
	int		i;
	int		j;
	int		compt;

	i = 0;
	j = 1;
	compt = 0;
	if ((ret + 1) % 21 != 0)
		ft_print_error();
	while (buf[i])
	{
		if (buf[i] == '#')
			compt++;
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			ft_print_error();
		if (buf[i] == '\n' && (i + 1) % 21 == 0)
			j--;
		else if (buf[i] == '\n' && (i + j) % 5 != 0)
			ft_print_error();
		i++;
	}
	if (compt != ((ret + 1) / 21) * 4)
		ft_print_error();
}

static void		ft_char_to_tab(int size, char *buf)
{
	t_compt g;
	int		k;
	char	tab[size][5];

	g.i = 0;
	k = 0;
	while (g.i < size)
	{
		g.j = 0;
		while (g.j < 4)
			tab[g.i][g.j++] = buf[k++];
		tab[g.i][g.j] = '\0';
		k++;
		if (buf[k] == '\n' && buf[k] != '\0')
			k++;
		g.i++;
	}
	g.i = 0;
	g.j = 0;
	ft_check_block(size, tab, g);
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
	return (0);
}
