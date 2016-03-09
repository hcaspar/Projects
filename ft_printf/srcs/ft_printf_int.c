/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 22:33:44 by hcaspar           #+#    #+#             */
/*   Updated: 2016/03/07 18:55:43 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf_int(int d, int i, int *n, t_struct *details)
{
	int		base;

	base = 10;
	if (details->conv == 'x' || details->conv == 'X')
		base = 16;
	else if (details->conv == 'o')
		base = 8;
	if (d < 0)
	{
		write(1, "-", 1);
		d = -d;
		(*n)++;
	}
	if (d >= base)
	{
		ft_printf_int(d / 10, i, n, details);
		d = d % base;
	}
	(*n)++;
	if (base == 16 && d >= 10)
		d = d + details->conv - 81;
	d = d + 48;
	write(1, &d, 1);
	return (i + 1);
}
