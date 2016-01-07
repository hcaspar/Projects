/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:54:18 by hcaspar           #+#    #+#             */
/*   Updated: 2016/01/07 18:43:04 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more.h"

t_compt2	loop_grid(t_compt2 g, char **grid, int i)
{
	while (g.i2 < i)
	{
		while (g.j2 < i && grid[g.i2][g.j2] != '.')
			g.j2++;
		if (grid[g.i2][g.j2] == '.')
			return (g);
		g.j2 = 0;
		g.i2++;
	}
	return (g);
}

t_compt2	loop_tab(t_compt2 g, int size, char tab[size][5])
{
	while (g.i < (g.i / 4) * 4 + 4)
	{
		g.j = 0;
		while (g.j < 4 && tab[g.i][g.j] != g.c)
			g.j++;
		if (tab[g.i][g.j] == g.c)
			return (g);
		g.i++;
	}
	return (g);
}
