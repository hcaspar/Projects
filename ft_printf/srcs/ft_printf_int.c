/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 22:33:44 by hcaspar           #+#    #+#             */
/*   Updated: 2016/04/04 17:08:14 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_int(unsigned long long d, t_struct *details, int v, int pad)
{
	if (v && !details->zero && !details->minus)
		ft_printf_pad(details, pad);
	if (v && details->sign)
	{
		write(1, "-", 1);
		details->n++;
	}
	else if (v && details->plus && ++details->n)
		write(1, "+", 1);
	else if (v && details->space && ++details->n)
		write(1, " ", 1);
	if (v && details->precision != -1)
		ft_count_digit(pad, details, 0);
	if (v && details->zero && !details->minus)
		ft_printf_pad(details, pad);
	if (v && details->precision == 0 && d != 0)
		details->precision = 1;
	if (d >= 10)
	{
		ft_printf_int(d / 10, details, 0, pad);
		d = d % 10;
	}
	d = d + 48;
	if (details->precision != 0 && ++details->n)
		write(1, &d, 1);
}

void	ft_printf_hex(unsigned long long d, t_struct *details, int v, int pad)
{
	if (v && !details->zero && (!details->minus || details->noflag))
		ft_printf_pad(details, pad);
	if ((d != 0 || details->point) && v && details->diese && ++details->n)
	{
		write(1, "0", 1);
		if (details->conv != 'o' && ++details->n)
			write(1, &details->conv, 1);
	}
	if (v && details->precision != -1 && (d != 0 || details->point))
		ft_count_digit(pad, details, 0);
	if (v && !details->minus && details->zero)
		ft_printf_pad(details, pad);
	if (d >= details->base)
	{
		ft_printf_hex(d / details->base, details, 0, pad);
		d = d % details->base;
	}
	if (details->base == 16 && d >= 10)
		d = d + details->conv - 81;
	d = d + 48;
	if ((details->precision != 0 || (details->conv == 'o' && details->diese)) \
		&& ++details->n)
		write(1, &d, 1);
}

void	ft_printf_u(unsigned long long d, t_struct *details, int v, int pad)
{
	if (v && !details->minus)
		ft_printf_pad(details, pad);
	if (v && details->precision != -1)
		ft_count_digit(pad, details, 0);
	if (v && details->precision == 0 && d != 0)
		details->precision = 1;
	if (d >= 10)
	{
		ft_printf_u(d / 10, details, 0, pad);
		d = d % 10;
	}
	d = d + 48;
	if (details->precision != 0)
	{
		details->n++;
		write(1, &d, 1);
	}
}

int		ft_count_int(unsigned long long d, t_struct *details, int pad)
{
	if (details->sign)
		pad++;
	else if (details->plus || details->space)
		pad++;
	while (d >= 10)
	{
		d = d / 10;
		pad++;
	}
	pad++;
	return (pad);
}

int		ft_count_hex(unsigned long long d, t_struct *details, int pad)
{
	unsigned long long	base;

	base = 16;
	if (details->conv == 'o')
		base = 8;
	if (details->conv == 'p')
		pad = pad + 2;
	else if (d != 0 && details->diese)
	{
		pad++;
		if (details->conv != 'o')
			pad++;
	}
	while (d >= base)
	{
		d = d / base;
		pad++;
	}
	return (pad);
}
