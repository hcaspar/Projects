/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:00:14 by hcaspar           #+#    #+#             */
/*   Updated: 2016/01/13 15:02:18 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*line;

	i = 1;
	ac = ac + 1 - 1;
	while (i == 1)
	{
		fd = open(av[1], O_RDONLY);
		i = get_next_line(fd, &line);
		ft_putendl(line);
		free(line);
		line = NULL;
		close(fd);
	}
	return (0);
}
