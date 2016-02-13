/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 14:03:58 by hcaspar           #+#    #+#             */
/*   Updated: 2016/02/13 16:45:02 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
	{
		i++;
	}
	if (!av[1][i])
	{
		write(1, "\n", 1);
		return (0);
	}
	j = i;
	while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
	{
		i++;
	}
	while (av[1][i] && (av[1][i] == '\t' || av[1][i] == ' '))
		i++;
	if (av[1][i] != '\0')
		k = 1;
	while (av[1][i])
	{
		while (av[1][i] && av[1][i] != '\t' && av[1][i] != ' ')
		{
			write(1, &av[1][i], 1);
			i++;
		}
		while (av[1][i] && (av[1][i] == '\t' || av[1][i] == ' '))
			i++;
		if (av[1][i] != '\0')
			write(1, " ", 1);
	}
	if (k == 1)
		write(1, " ", 1);
	while (av[1][j] && av[1][j] != ' ' && av[1][j] != '\t')
	{
		write(1, &av[1][j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
