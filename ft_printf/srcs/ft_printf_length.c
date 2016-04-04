/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 03:00:39 by hcaspar           #+#    #+#             */
/*   Updated: 2016/04/04 22:36:00 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_length(int nb, t_struct *details)
{
	char	c;

	if (nb >= 10)
	{
		ft_printf_length(nb / 10, details);
		nb = nb % 10;
	}
	details->n++;
	c = nb + 48;
	write(1, &c, 1);
}

void		ft_conv_porn(t_struct *details)
{
	if (details->conv == 'n')
		ft_printf_length(details->n, details);
	else
		ft_conv_percent(details);
}
