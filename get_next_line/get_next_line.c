/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:48:45 by hcaspar           #+#    #+#             */
/*   Updated: 2016/01/12 15:10:47 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*find_end_of_line(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	buf[i] = '\0';
	return (buf);
}

void		ft_realloc(char **line, int len)
{
	char	*new;
	int		i;

	new = *line;
	free(*line);
	*line = (char*)malloc(sizeof(char) * (len + ft_strlen(new)) + 1);
	i = -1;
	while ((new)[++i])
		(*line)[i] = new[i]; 
	(*line)[i] = '\0';
}

void		ft_join(char buf[BUFF_SIZE + 1], char **line)
{
	int		len;
	int		i;

	i = -1;
	len = 0;
	if (*line == NULL)
		*line = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	else
	{
		ft_realloc(line, BUFF_SIZE);
		len = ft_strlen(*line);
	}
	while (buf[++i])
		(*line)[len + i] = buf[i];
	(*line)[len + i] = '\0';
}

int			buf_read(int fd, char **line)
{
	int		i;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	*line = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		ft_join(buf, line);
	}
//	join = find_end_of_line(join);
	i = -1;
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	int		ret;

	if ((ret = buf_read(fd, line)) == -1)
		return (ret);
	ft_putendl(*line);
	return (0);
}
