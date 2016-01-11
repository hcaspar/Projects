/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:24:31 by hcaspar           #+#    #+#             */
/*   Updated: 2016/01/11 13:38:11 by hcaspar          ###   ########.fr       */
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

t_compt2	ft_assemble(char **grid, int size, char tab[size][5], t_compt2 g)
{
	while (g.b != 4)
	{
		g = loop_tab(g, size, tab);
		g = loop_grid(g, grid);
		g = ft_place(grid, size, tab, g);
		if (g.b == 4 && (g.i * 4) / 4 + 4 < size)
		{
			g = next_block(g);
			g = ft_assemble(grid, size, tab, g);
		}
		if (g.b != 4)
		{
			if (g.b == -1)
			{
				if (g.i / 4 == 0)
				{
					g.end = 0;
					return (g);
				}
				else
					g = prev_block(g, grid);
			}
			loop_erase(g, grid);
			g.j2++;
			g.b = 1;
		}
	}
	return (g);
}

void		ft_create_map(int size, char tab[size][5], int i)
{
	t_compt		g;
	t_compt2	g2;
	char		**grid;

	while (i * i < size)
		i++;
	g2 = ft_struct_init(g2, i);
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
	g2 = ft_assemble(grid, size, tab, g2);
	if (g2.end == 0)
	{
		ft_free_tab(grid);
		ft_create_map(size, tab, i + 1);
	}
	else
	{
		ft_print_grid(grid);
		ft_free_tab(grid);
	}
}
