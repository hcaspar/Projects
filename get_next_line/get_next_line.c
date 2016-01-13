/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:48:45 by hcaspar           #+#    #+#             */
/*   Updated: 2016/01/13 15:01:55 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			find_end_of_line(char **line)
{
	static int		i = -1;
	int				j;
	int				k;
	char			*tmp;

	i++;
	k = i;
	tmp = (*line);
	free(*line);
	*line = NULL;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	j = i - k;
	*line = (char*)malloc(sizeof(char) * j + 1);
	(*line)[j] = '\0';
	while (--j != -1)
		(*line)[j] = tmp[k + j];
//	free(tmp);
	if ((*line)[i] == '\0')
		return (0);
	return (1);
}

void		ft_realloc(char **line, int len)
{
	char			*new;
	int				i;

	new = *line;
	free(*line);
	*line = NULL;
	*line = (char*)malloc(sizeof(char) * (len + ft_strlen(new)) + 1);
	i = -1;
	while (new[++i])
		(*line)[i] = new[i];
	(*line)[i] = '\0';
}

void		ft_join(char buf[BUFF_SIZE + 1], char **line)
{
	int				len;
	int				i;

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
	int				ret;
	char			buf[BUFF_SIZE + 1];

	*line = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		ft_join(buf, line);
	}
	if (ret == 0)
		return (0);
	return (ret);
}

int			get_next_line(int const fd, char **line)
{
	int		ret;

	ret = -1;
	if ((ret = buf_read(fd, line)) == -1)
		return (ret);
	ret = find_end_of_line(line);
	return (ret);
}
