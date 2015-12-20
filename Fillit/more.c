/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:24:31 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/20 18:56:04 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more.h"

void		ft_print_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void		ft_print_tab(int size, char tab[size][5])
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putendl(tab[i]);
		i++;
	}
}

void		ft_free_tab(char **grid)
{
	t_compt	g;

	g.i = 0;
	g.j = 0;
	while (grid[g.i])
		g.i++;
	while (g.i != 0)
	{
		if (grid[g.i])
			free(grid[g.i]);
		g.i--;
	}
	if (grid)
		free(grid);
}

int			ft_assemble(char **grid, int size, char tab[size][5])
{
	t_compt2	g;

	g.i = 0;
	g.i2 = 0;
	g.j2 = 0;
	while (g.i != size)
	{
		g.j = 0;
		while (g.j != 4)
		{
			if (tab[g.i][g.j] == 'A' + g.i / 4)
			{
				g.b = 1;
				g.c = 'A' + g.i / 4;
				while (grid[g.i2][g.j2] != '.')
					g.j2++;
				if ((g.b = ft_place(grid, size, tab, g)) != 4)
					return (0);
				g.j = 3;
				g.i = (g.i / 4) * 4 + 3;
			}
			g.j++;
		}
		g.i++;
	}
	g.i = 0;
	g.j = 0;
	while (grid[g.i])
	{
		ft_putendl(grid[g.i]);
		g.i++;
	}
	ft_free_tab(grid);
	ft_print_tab(size, tab);
	return (1);
}

void		ft_create_map(int size, char tab[size][5], int i)
{
	t_compt	g;
	char	**grid;

	while (i * i < size)
		i++;
	g.i = 0;
	if (!(grid = (char**)malloc(sizeof(char*) * (i + 1))))
		ft_print_error();
	while (g.i < i)
	{
		g.j = 0;
		if (!(grid[g.i] = ft_strnew(i)))
			ft_print_error();
		while (g.j < i)
		{
			grid[g.i][g.j] = '.';
			g.j++;
		}
		g.i++;
	}
	grid[g.i] = NULL;
	if (ft_assemble(grid, size, tab) == 0)
	{
		ft_free_tab(grid);
		ft_create_map(size, tab, i + 1);
	}
}
