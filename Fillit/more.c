/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:24:31 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/12 18:30:28 by hcaspar          ###   ########.fr       */
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

void		ft_create_map(int size, char tab[size][5], int i)
{
	t_compt	g;
	char	**grid;

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
	g.i = 0;
	g.j = 0;
	while (grid[g.i])
	{
		ft_putendl(grid[g.i]);
		g.i++;
	}
	ft_free_tab(grid);
	ft_print_tab(size, tab);
}
