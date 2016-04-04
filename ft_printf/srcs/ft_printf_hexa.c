/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 20:03:09 by hcaspar           #+#    #+#             */
/*   Updated: 2016/04/04 22:09:41 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_count_u(unsigned long long d, int pad)
{
	while (d >= 10)
	{
		d = d / 10;
		pad++;
	}
	pad++;
	return (pad);
}

void		ft_conv_u(unsigned long long d, t_struct *details)
{
	int		pad;

	if (details->precision != -1)
		details->zero = 0;
	pad = ft_count_u(d, 0);
	if (details->precision != -1)
		pad = ft_count_digit(pad, details, 1);
	ft_printf_u(d, details, 1, pad);
	if (details->minus)
		ft_printf_pad(details, pad);
}

int			ft_noconv(t_struct *details)
{
	char	c;

	c = details->conv;
	if (c != 'c' && c != 'C' && c != 's' && c != 'S' && c != 'p' && c != '%' \
		&& c != 'x' && c != 'X' && c != 'o' && c != 'd' && c != 'i' \
		&& c != 'u' && c != 'U' && c != 'D' && c != 'O' && c != 'n' && c != 0)
	{
		c = ' ';
		if (details->zero)
			c = '0';
		while (details->width > 1 && !details->minus && ++details->n)
		{
			write(1, &c, 1);
			details->width--;
		}
		details->n++;
		write(1, &details->conv, 1);
		while (details->width > 1 && details->minus && ++details->n)
		{
			write(1, &c, 1);
			details->width--;
		}
		return (0);
	}
	return (1);
}
