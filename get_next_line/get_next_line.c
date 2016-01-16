/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:48:45 by hcaspar           #+#    #+#             */
/*   Updated: 2016/01/16 10:39:33 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			find_end_of_line(char **line, char **text)
{
	int				i;
	int				j;
	char			*tmp;

	i = 0;
	while ((*text)[i] && (*text)[i] != '\n')
		i++;
	*line = (char*)malloc(sizeof(char) * i + 1);
	j = -1;
	while ((*text)[++j] && (*text)[j] != '\n')
		(*line)[j] = (*text)[j];
	(*line)[j] = '\0';
	if ((*text)[j] == '\0')
		return (0);
	tmp = *text;
	j = ft_strlen(*text) - i - 1;
	*text = (char*)malloc(sizeof(char) * j + 1);
	j = -1;
	while (tmp[++i])
		(*text)[++j] = tmp[i];
	(*text)[j + 1] = '\0';
	free(tmp);
	return (1);
}

void		ft_realloc(char **text, int len)
{
	char			*new;
	int				i;

	new = *text;
	*text = NULL;
	*text = (char*)malloc(sizeof(char) * (len + ft_strlen(new)) + 1);
	i = -1;
	while (new[++i])
		(*text)[i] = new[i];
	(*text)[i] = '\0';
	free(new);
}

void		ft_join(char buf[BUFF_SIZE + 1], int ret, char **text)
{
	int				len;
	int				i;

	i = -1;
	len = 0;
	if (*text == NULL)
		*text = (char*)malloc(sizeof(char) * (ret + 1));
	else
	{
		ft_realloc(text, ret);
		len = ft_strlen(*text);
	}
	while (buf[++i])
		(*text)[len + i] = buf[i];
	(*text)[len + i] = '\0';
}

int			buf_read(int fd, char **text)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		ft_join(buf, ret, text);
	}
	return (ret);
}

int			get_next_line(int const fd, char **line)
{
	static char		*text = NULL;
	int				ret;

	ret = -1;
	if (text == NULL)
		if ((ret = buf_read(fd, &text)) == -1)
			return (ret);
	ret = find_end_of_line(line, &text);
	if (ret == 0 && text)
		free(text);
	return (ret);
}
