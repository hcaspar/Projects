/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:02:16 by hcaspar           #+#    #+#             */
/*   Updated: 2016/03/07 19:03:14 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf_pad_string(char *s, int n, t_struct *details)
{
	char	c;
	int		compt;

	compt = 0;
	c = ' ';
	if (details->flag == '0')
		c = '0';
	if (details->precision == -1)
		while (s[compt])
			compt++;
	while (s[compt] && compt < details->precision)
		compt++;
	while (compt < details->width)
	{
		write(1, &c, 1);
		compt++;
		n++;
	}
	return (n);
}

int			ft_printf_pad(int d, int n, t_struct *details)
{
	int		power;
	char	c;

	c = ' ';
	if (details->flag == '0')
		c = '0';
	power = 1;
	while (d >= 10)
	{
		power++;
		d = d / 10;
	}
	while (power < details->width)
	{
		write(1, &c, 1);
		n++;
		power++;
	}
	return (n);
}
