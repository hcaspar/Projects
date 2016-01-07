/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:24:31 by hcaspar           #+#    #+#             */
/*   Updated: 2016/01/07 20:35:15 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more.h"

void		ft_print_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void		ft_print_grid(char **grid)
{
	int		i;

	i = 0;
	while (grid[i])
	{
		ft_putendl(grid[i]);
		i++;
	}
}

void		ft_free_tab(char **grid)
{
	t_compt	g;

	g.i = 0;
	g.j = 0;
	while (grid[g.i] != NULL)
	{
		if (grid[g.i])
			free(grid[g.i]);
		g.i++;
	}
	if (grid)
		free(grid);
	grid = NULL;
}

int			ft_assemble(char **grid, int size, char tab[size][5], int i)
{
	t_compt2	g;
	t_compt2	g2;

	g = ft_struct_init(g, i);
	while (g.i < size)
	{
		g = loop_tab(g, size, tab);
		g = loop_grid(g, grid, i);
		g2 = g;
		g2 = ft_check(grid, size, tab, g2);
		if (g2.b != 4 && g2.i2 == i && g2.j2 == i - 1)
			return (0);
		if (g2.b == 4)
		{
			g = ft_place(grid, size, tab, g);
			g.i = (g.i / 4) * 4 + 4;
			g.c = g.c + 1;
		}
		else
			g.j2++;
		g.b = 1;
	}
	ft_print_grid(grid);
	return (1);
}

void		ft_create_map(int size, char tab[size][5], int i)
{
	t_compt	g;
	char	**grid;

	while (i * i < size)
		i++;
	g.i = -1;
	if (!(grid = (char**)malloc(sizeof(char*) * (i + 1))))
		ft_print_error();
	while (++g.i < i)
	{
		g.j = -1;
		if (!(grid[g.i] = ft_strnew(i)))
			ft_print_error();
		while (++g.j < i)
			grid[g.i][g.j] = '.';
	}
	grid[g.i] = NULL;
	if (ft_assemble(grid, size, tab, i) == 0)
	{
		ft_free_tab(grid);
		ft_create_map(size, tab, i + 1);
	}
	else
		ft_free_tab(grid);
}
