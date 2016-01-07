/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_one_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:30:17 by hcaspar           #+#    #+#             */
/*   Updated: 2016/01/07 16:05:03 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more.h"

t_compt2	ft_trash12(char **grid, int size, char tab[size][5], t_compt2 g)
{
	g.j2++;
	g.b++;
	g.j++;
	g = ft_check(grid, size, tab, g);
	g.j--;
	g.j2--;
	return (g);
}

t_compt2	ft_trash22(char **grid, int size, char tab[size][5], t_compt2 g)
{
	g.i2++;
	g.b++;
	g.i++;
	g = ft_check(grid, size, tab, g);
	g.i--;
	g.i2--;
	return (g);
}

t_compt2	ft_trash32(char **grid, int size, char tab[size][5], t_compt2 g)
{
	g.j2--;
	g.b++;
	g.j--;
	g = ft_check(grid, size, tab, g);
	g.j++;
	g.j2++;
	return (g);
}

t_compt2	ft_check(char **grid, int size, char tab[size][5], t_compt2 g)
{
	if (g.b < 4 && tab[g.i][g.j + 1] == g.c && grid[g.i2][g.j2 + 1] == '.')
	{
		g = ft_trash12(grid, size, tab, g);
	}
	if (g.b < 4 && g.i < size - 1 && g.i2 + 1 < g.s && \
		tab[g.i + 1][g.j] == g.c && grid[g.i2 + 1][g.j2] == '.')
	{
		g = ft_trash22(grid, size, tab, g);
	}
	if (g.b < 4 && g.j != 0 && tab[g.i][g.j - 1] == g.c && \
		grid[g.i2][g.j2 - 1] == '.')
	{
		g = ft_trash32(grid, size, tab, g);
	}
	return (g);
}
