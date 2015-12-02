/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:18:50 by hcaspar           #+#    #+#             */
/*   Updated: 2015/11/28 16:50:19 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	if ((new = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	i = 0;
	ft_strcpy(new, s);
	while (s[i])
	{
		new[i] = f(new[i]);
		i++;
	}
	return (new);
}
