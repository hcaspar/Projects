/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 00:29:31 by hcaspar           #+#    #+#             */
/*   Updated: 2016/02/02 03:00:03 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_string(char *s, int i, int *n)
{
	int j;

	j = 0;
	while (s[j])
		j++;
	(*n) = (*n) + j;
	write(1, s, j);
	return (i + 2);
}
