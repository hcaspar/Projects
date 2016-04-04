/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:59:04 by hcaspar           #+#    #+#             */
/*   Updated: 2016/04/04 21:40:32 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_conv_c(int c, t_struct *details)
{
	if (details->zero || details->noflag)
		ft_printf_pad_string("c", details);
	ft_printf_char(c, details);
	if (details->minus)
		ft_printf_pad_string("c", details);
}

void	ft_conv_c_uni(wint_t c, t_struct *details)
{
	if (details->noflag || details->zero)
		ft_printf_pad_string("c", details);
	ft_printf_char_uni(c, details);
	if (details->minus)
		ft_printf_pad_string("c", details);
}

void	ft_conv_s(char *s, t_struct *details)
{
	if (s == NULL)
		s = "(null)";
	if (details->noflag || details->zero)
		ft_printf_pad_string(s, details);
	ft_printf_string(s, details);
	if (details->minus)
		ft_printf_pad_string(s, details);
}

void	ft_conv_s_uni(wchar_t *s, t_struct *details)
{
	if (s == NULL)
		s = L"(null)";
	if (details->noflag || details->zero)
		ft_printf_pad_string_uni(s, details);
	ft_printf_string_uni(s, details);
	if (details->minus == '-')
		ft_printf_pad_string_uni(s, details);
}

void	ft_conv_percent(t_struct *details)
{
	if (details->noflag || details->zero)
		ft_printf_pad(details, 1);
	ft_printf_percent(details);
	if (details->minus)
		ft_printf_pad(details, 1);
}
