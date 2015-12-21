/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:12:29 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/21 15:12:17 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more.h"

t_compt2	ft_trash1(t_compt2 g)
{
	g.j2++;
	g.b++;
	g.j++;
	return (g);
}

t_compt2	ft_trash2(t_compt2 g)
{
	g.i2++;
	g.b++;
	g.i++;
	return (g);
}

t_compt2	ft_trash3(t_compt2 g)
{
	g.j2--;
	g.b++;
	g.j--;
	return (g);
}

int			ft_place(char **grid, int size, char tab[size][5], t_compt2 g)
{
	grid[g.i2][g.j2] = g.c;
	if (g.b < 4 && tab[g.i][g.j + 1] == g.c && grid[g.i2][g.j2 + 1] == '.')
	{
		g = ft_trash1(g);
		g.b = ft_place(grid, size, tab, g);
		g.j--;
	}
	if (g.b < 4 && g.i < size - 1 && g.i2 + 1 < g.s && \
		tab[g.i + 1][g.j] == g.c && grid[g.i2 + 1][g.j2] == '.')
	{
		g = ft_trash2(g);
		g.b = ft_place(grid, size, tab, g);
		g.i--;
	}
	if (g.b < 4 && g.j != 0 && tab[g.i][g.j - 1] == g.c && \
		grid[g.i2][g.j2 - 1] == '.')
	{
		g = ft_trash3(g);
		g.b = ft_place(grid, size, tab, g);
		g.j++;
	}
	return (g.b);
}
