/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 00:29:31 by hcaspar           #+#    #+#             */
/*   Updated: 2016/03/07 18:54:09 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_string(char *s, int i, int *n, t_struct *details)
{
	int j;

	j = 0;
	if (details->precision != -1)
	{
		while (s[j] && j < details->precision)
			j++;
		(*n) = (*n) + j;
		write(1, s, j);
	}
	else
	{
		while (s[j])
			j++;
		(*n) = (*n) + j;
		write(1, s, j);
	}
	return (i + 1);
}
