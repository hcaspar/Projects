/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:48:45 by hcaspar           #+#    #+#             */
/*   Updated: 2016/01/18 17:45:31 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			find_end_of_line(char **line, t_link *tmp)
{
	int				i;
	int				j;
	char			*temp;

	i = 0;
	while ((tmp->text)[i] && (tmp->text)[i] != '\n')
		i++;
	*line = (char*)malloc(sizeof(char) * i + 1);
	j = -1;
	while ((tmp->text)[++j] && (tmp->text)[j] != '\n')
		(*line)[j] = (tmp->text)[j];
	(*line)[j] = '\0';
	if ((tmp->text)[j] == '\0')
		return (0);
	temp = tmp->text;
	j = ft_strlen(tmp->text) - i - 1;
	tmp->text = (char*)malloc(sizeof(char) * j + 1);
	j = -1;
	while (temp[++i])
		(tmp->text)[++j] = temp[i];
	(tmp->text)[j + 1] = '\0';
	free(temp);
	return (1);
}

static void			ft_join(char buf[BUFF_SIZE + 1], long long ret, t_link *tmp)
{
	char			*new;
	int				i;
	size_t			len;
	int				j;

	i = -1;
	len = 0;
	if (tmp->text == NULL)
		tmp->text = (char*)malloc(sizeof(char) * (ret + 1));
	else
	{
		new = tmp->text;
		tmp->text = NULL;
		tmp->text = (char*)malloc(sizeof(char) * (ret + ft_strlen(new)) + 1);
		j = -1;
		while (new[++j])
			(tmp->text)[j] = new[j];
		(tmp->text)[j] = '\0';
		free(new);
		len = ft_strlen(tmp->text);
	}
	while (buf[++i])
		(tmp->text)[len + i] = buf[i];
	(tmp->text)[len + i] = '\0';
}

static int			buf_read(t_link *tmp)
{
	long long		ret;
	char			buf[BUFF_SIZE + 1];

	while ((ret = read(tmp->fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		if (ret == 0)
			break ;
		buf[ret] = '\0';
		ft_join(buf, ret, tmp);
	}
	return (1);
}

static t_link		*init_list(int const fd, t_link **begin_list)
{
	t_link			*tmp;

	tmp = *begin_list;
	while (tmp != NULL && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		tmp = (t_link*)malloc(sizeof(t_link));
		tmp->fd = fd;
		tmp->text = NULL;
		tmp->eof = 0;
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	return (tmp);
}

int					get_next_line(int const fd, char **line)
{
	static t_link	*begin_list = NULL;
	t_link			*tmp;
	int				ret;

	if (begin_list == NULL)
	{
		begin_list = (t_link*)malloc(sizeof(t_link));
		begin_list->text = NULL;
		begin_list->next = NULL;
		begin_list->fd = fd;
		begin_list->eof = 0;
	}
	tmp = init_list(fd, &begin_list);
	if (tmp->eof == 1)
		return (0);
	ret = -1;
	if (tmp->text == NULL)
		if (BUFF_SIZE <= 0 || (ret = buf_read(tmp)) == -1)
			return (-1);
	if ((ret = find_end_of_line(line, tmp)) == 0)
		tmp->eof = 1;
	if (ret == 0 && tmp->text)
		free(tmp->text);
	return (ret);
}
