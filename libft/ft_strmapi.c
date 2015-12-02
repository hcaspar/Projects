/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:31:22 by hcaspar           #+#    #+#             */
/*   Updated: 2015/11/28 16:49:57 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	if ((new = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	i = 0;
	ft_strcpy(new, s);
	while (s[i])
	{
		new[i] = f(i, new[i]);
		i++;
	}
	return (new);
}
