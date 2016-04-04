/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 00:29:31 by hcaspar           #+#    #+#             */
/*   Updated: 2016/04/04 20:12:19 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_string(char *s, t_struct *details)
{
	int j;

	j = 0;
	if (details->precision != -1)
	{
		while (s[j] && j < details->precision)
			j++;
		details->n = details->n + j;
		write(1, s, j);
	}
	else
	{
		while (s[j])
			j++;
		details->n = details->n + j;
		write(1, s, j);
	}
}

void	ft_printf_string_uni(wchar_t *s, t_struct *details)
{
	int j;

	j = 0;
	if (details->precision != -1)
	{
		while (s[j] && j < details->precision)
		{
			ft_printf_char_uni((wint_t)s[j], details);
			j++;
		}
	}
	else
	{
		while (s[j])
		{
			ft_printf_char_uni((wint_t)s[j], details);
			j++;
		}
	}
}
