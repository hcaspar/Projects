/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 09:27:33 by hcaspar           #+#    #+#             */
/*   Updated: 2016/02/13 13:40:42 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **av)
{
	char	tab[2048];
	int		i;
	int		j;
	int		compt;

	i = 0;
	j = 0;
	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (i < 2048)
	{
		tab[i] = 0;
		i++;
	}
	i = 0;
	while (av[1][j])
	{
		if (av[1][j] == '>')
			i++;
		if (av[1][j] == '<')
			i--;
		if (av[1][j] == '+')
			tab[i]++;
		if (av[1][j] == '-')
			tab[i]--;
		if (av[1][j] == '.')
			write(1, &tab[i], 1);
		if (av[1][j] == '[' && tab[i] == 0)
		{
			compt = 1;
			while (compt != 0)
			{
				j++;
				if (av[1][j] == '[')
					compt++;
				if (av[1][j] == ']')
					compt--;
			}
		}
		if (av[1][j] == ']' && tab[i] != 0)
		{
			compt = 1;
			while (compt != 0)
			{
				j--;
				if (av[1][j] == '[')
					compt--;
				if (av[1][j] == ']')
					compt++;
			}
		}
		j++;
	}
	return (0);
}
