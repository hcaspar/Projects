/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:12:29 by hcaspar           #+#    #+#             */
/*   Updated: 2016/01/08 18:12:45 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more.h"

t_compt2	ft_trash1(char **grid, int size, char tab[size][5], t_compt2 g)
{
	g.j2++;
	g.b++;
	g.j++;
	g = ft_place(grid, size, tab, g);
	g.j--;
	g.j2--;
	return (g);
}

t_compt2	ft_trash2(char **grid, int size, char tab[size][5], t_compt2 g)
{
	g.i2++;
	g.b++;
	g.i++;
	g = ft_place(grid, size, tab, g);
	g.i--;
	g.i2--;
	return (g);
}

t_compt2	ft_trash3(char **grid, int size, char tab[size][5], t_compt2 g)
{
	g.j2--;
	g.b++;
	g.j--;
	g = ft_place(grid, size, tab, g);
	g.j++;
	g.j2++;
	return (g);
}

t_compt2	ft_place(char **grid, int size, char tab[size][5], t_compt2 g)
{
	grid[g.i2][g.j2] = g.c;
	if (g.b < 4 && tab[g.i][g.j + 1] == g.c && grid[g.i2][g.j2 + 1] == '.')
		g = ft_trash1(grid, size, tab, g);
	else if (g.b < 4 && tab[g.i][g.j + 1] == g.c)
		return (g);
	if (g.b < 4 && g.i < size - 1 && g.i2 + 1 < g.s && \
		tab[g.i + 1][g.j] == g.c && grid[g.i2 + 1][g.j2] == '.')
		g = ft_trash2(grid, size, tab, g);
	else if (g.b < 4 && g.i < size - 1 && tab[g.i + 1][g.j] == g.c)
		return (g);
	if (g.b < 4 && g.j != 0 && tab[g.i][g.j - 1] == g.c && \
		g.j2 != 0 && grid[g.i2][g.j2 - 1] == '.')
		g = ft_trash3(grid, size, tab, g);
	else if (g.b < 4 && g.j != 0 && tab[g.i][g.j - 1] == g.c)
		return (g);
	return (g);
}

t_compt2	ft_struct_init(t_compt2 g, int i)
{
	g.i = 0;
	g.j = 0;
	g.i2 = 0;
	g.j2 = 0;
	g.b = 1;
	g.s = i;
	g.c = 'A';
	g.jpos = 0;
	return (g);
}
