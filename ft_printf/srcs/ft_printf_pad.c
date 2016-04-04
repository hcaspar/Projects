/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:02:16 by hcaspar           #+#    #+#             */
/*   Updated: 2016/04/04 21:51:17 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_pad_string(char *s, t_struct *details)
{
	char	c;
	int		compt;

	compt = 0;
	c = ' ';
	if (details->zero)
		c = '0';
	if (details->precision == -1 || details->conv == 'c')
		while (s[compt])
			compt++;
	while (s[compt] && compt < details->precision)
		compt++;
	while (compt < details->width)
	{
		write(1, &c, 1);
		compt++;
		details->n++;
	}
}

void		ft_printf_pad_string_uni(wchar_t *s, t_struct *details)
{
	char	c;
	int		compt;

	compt = 0;
	c = ' ';
	if (details->zero)
		c = '0';
	if (details->precision == -1)
	{
		while (s[compt])
			compt++;
	}
	while (s[compt] && compt < details->precision)
		compt++;
	while (compt < details->width)
	{
		write(1, &c, 1);
		compt++;
		details->n++;
	}
}

void		ft_printf_pad(t_struct *details, int power)
{
	char	c;

	c = ' ';
	if (details->zero && !details->minus)
		c = '0';
	if (details->precision == 0 && details->conv != '%')
		power--;
	while (power < details->width)
	{
		write(1, &c, 1);
		power++;
		details->n++;
	}
}

int			ft_count_digit(int pad, t_struct *details, int v)
{
	int			d;

	if (v)
	{
		d = details->precision - pad;
		if (details->space || details->plus || details->sign)
			d++;
		if (details->diese && (details->conv == 'x' || details->conv == 'X'))
			d = d + 2;
		details->digit = d;
		while (0 < d--)
			pad++;
	}
	else
	{
		d = details->digit;
		while (d > 0)
		{
			details->n++;
			write(1, "0", 1);
			d--;
		}
	}
	return (pad);
}
