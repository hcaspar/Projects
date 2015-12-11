/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:31:27 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/11 17:25:47 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more.h"

static void		ft_check_map(int ret, char *buf)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	if ((ret + 1) % 21 != 0)
		ft_print_error();
	while (buf[i])
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			ft_print_error();
		if (buf[i] == '\n' && (i + 1) % 21 == 0)
			j--;
		else if (buf[i] == '\n' && (i + j) % 5 != 0)
			ft_print_error();
		i++;
	}
}

static void		ft_char_to_tab(int ret, char *buf)
{
	int		i;
	int		j;
	int		k;
	char	tab[4 * ((ret + 1) / 21)][5];

	i = 0;
	k = 0;
	while (i < 4 * ((ret + 1) / 21))
	{
		j = 0;
		while (j < 4)
		{
			tab[i][j++] = buf[k++];
		}
		tab[i][j] = '\0';
		k++;
		if (buf[k] == '\n' && buf[k] != '\0')
			k++;
		i++;
	}
	ft_print_tab(ret, tab);
}

int				main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[1024];

	if (ac != 2)
		ft_print_error();
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_print_error();
	if ((ret = read(fd, buf, 1020)) == -1)
		ft_print_error();
	if ((close(fd)) == -1)
		ft_print_error();
	buf[ret] = '\0';
	ft_check_map(ret, buf);
	ft_char_to_tab(ret, buf);
}
