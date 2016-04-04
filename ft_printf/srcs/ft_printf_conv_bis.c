/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 18:35:48 by hcaspar           #+#    #+#             */
/*   Updated: 2016/04/04 22:35:53 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_conv_d(long long k, t_struct *details)
{
	int					pad;
	unsigned long long	d;

	if (details->precision != -1)
		details->zero = 0;
	if (k < 0)
	{
		details->sign = 1;
		d = ~k + 1;
	}
	else
		d = (unsigned long long)k;
	pad = ft_count_int(d, details, 0);
	if (details->precision != -1)
		pad = ft_count_digit(pad, details, 1);
	ft_printf_int(d, details, 1, pad);
	if (details->minus)
		ft_printf_pad(details, pad);
}

void		ft_conv_hex(unsigned long long d, t_struct *details)
{
	int		pad;

	if (details->precision != -1)
		details->zero = 0;
	if (details->conv == 'O')
		details->conv = 'o';
	if (details->conv == 'o')
		details->base = 8;
	pad = ft_count_hex(d, details, 1);
	if (details->precision != -1)
		pad = ft_count_digit(pad, details, 1);
	if (details->conv == 'p')
	{
		details->point = 1;
		details->conv = 'x';
		details->diese = 1;
		details->digit = details->digit + 2;
	}
	ft_printf_hex(d, details, 1, pad);
	if (details->minus)
		ft_printf_pad(details, pad);
}

static void	ft_rerecasts(void *d, t_struct *details)
{
	if (((details->conv == 'o' || details->conv == 'x' || details->conv == 'X')\
		&& details->mod == 'l') || details->conv == 'O')
		ft_conv_hex((unsigned long long)(unsigned long)d, details);
	else if ((details->conv == 'o' || details->conv == 'x' || \
		details->conv == 'X') && details->mod == 'h')
		ft_conv_hex((unsigned long long)(unsigned short)d, details);
	else if ((details->conv == 'o' || details->conv == 'x' || \
			details->conv == 'X') && details->mod == 'h' + 'h')
		ft_conv_hex((unsigned long long)(unsigned char)d, details);
	else if ((details->conv == 'o' || details->conv == 'x' || \
			details->conv == 'X') && details->mod == 'l' + 'l')
		ft_conv_hex((unsigned long long)d, details);
	else if ((details->conv == 'o' || details->conv == 'x' || \
			details->conv == 'X') && details->mod == 'j')
		ft_conv_hex((unsigned long long)(uintmax_t)d, details);
	else if ((details->conv == 'o' || details->conv == 'x' || \
			details->conv == 'X') && details->mod == 'z')
		ft_conv_hex((unsigned long long)(size_t)d, details);
	else if ((details->conv == 'o' || details->conv == 'x' || \
			details->conv == 'X') && details->mod == 0)
		ft_conv_hex((unsigned long long)(unsigned int)d, details);
	else if (details->conv == 'p')
		ft_conv_hex((unsigned long long)(long)d, details);
}

static void	ft_recasts(void *d, t_struct *details)
{
	if (details->mod == 'h' && (details->conv == 'd' || details->conv == 'i'))
		ft_conv_d((long long)(short)d, details);
	else if ((details->conv == 'd' || details->conv == 'i') && \
			details->mod == 'h' + 'h')
		ft_conv_d((long long)(char)d, details);
	else if (((details->conv == 'd' || details->conv == 'i') && \
			details->mod == 'l') || details->conv == 'D')
		ft_conv_d((long long)(long)d, details);
	else if ((details->conv == 'd' || details->conv == 'i') && \
			details->mod == 'l' + 'l')
		ft_conv_d((long long)d, details);
	else if ((details->conv == 'd' || details->conv == 'i') && \
			details->mod == 'j')
		ft_conv_d((long long)(intmax_t)d, details);
	else if ((details->conv == 'd' || details->conv == 'i') && \
			details->mod == 'z')
		ft_conv_d((long long)(ssize_t)d, details);
	else if ((details->conv == 'd' || details->conv == 'i') && \
			details->mod == 0)
		ft_conv_d((long long)(int)d, details);
	else if ((details->conv == 'u' && details->mod == 'l') || \
			details->conv == 'U')
		ft_conv_u((unsigned long long)(unsigned long)d, details);
}

void		ft_casts(void *d, t_struct *details)
{
	ft_recasts(d, details);
	ft_rerecasts(d, details);
	if ((details->conv == 'c' && details->mod == 'l') || \
			details->conv == 'C')
		ft_conv_c_uni((long long)(wint_t)d, details);
	else if (details->conv == 'c')
		ft_conv_c((long long)(int)d, details);
	else if ((details->mod == 'l' && details->conv == 's') || \
			details->conv == 'S')
		ft_conv_s_uni((wchar_t*)d, details);
	else if (details->conv == 's')
		ft_conv_s((char*)d, details);
	else if (details->conv == 'u' && details->mod == 'h')
		ft_conv_u((unsigned long long)(unsigned short)d, details);
	else if (details->conv == 'u' && details->mod == 'h' + 'h')
		ft_conv_u((unsigned long long)(unsigned char)d, details);
	else if (details->conv == 'u' && details->mod == 'l' + 'l')
		ft_conv_u((unsigned long long)d, details);
	else if (details->conv == 'u' && details->mod == 'j')
		ft_conv_u((unsigned long long)(uintmax_t)d, details);
	else if (details->conv == 'u' && details->mod == 'z')
		ft_conv_u((unsigned long long)(size_t)d, details);
	else if (details->conv == 'u' && details->mod == 0)
		ft_conv_u((unsigned long long)(unsigned int)d, details);
}
