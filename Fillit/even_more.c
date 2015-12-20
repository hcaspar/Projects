/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:12:29 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/20 19:02:29 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more.h"

int		ft_place(char **grid, int size, char tab[size][5], t_compt2 g)
{
	grid[g.i2][g.j2] = g.c;
	if (g.b != 4 && grid[g.i2][g.j2 + 1] && tab[g.i][g.j + 1] == g.c)
	{
		g.j2++;
		g.b++;
		g.j++;
		g.b = ft_place(grid, size, tab, g);
		g.j--;
	}
	if (g.b != 4 && g.i != size - 1 && tab[g.i + 1][g.j] == g.c)
	{
		g.i2++;
		g.b++;
		g.i++;
		g.b = ft_place(grid, size, tab, g);
		g.i--;
	}
	if (g.b != 4 && g.j != 0 && tab[g.i][g.j - 1] == g.c)
	{
		g.j2--;
		g.b++;
		g.j--;
		g.b = ft_place(grid, size, tab, g);
		g.j++;
	}
	return (g.b);
}
