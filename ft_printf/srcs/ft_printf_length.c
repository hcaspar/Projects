/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 03:00:39 by hcaspar           #+#    #+#             */
/*   Updated: 2016/02/02 03:54:46 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_length(int i, int nb, int *n)
{
	char	c;

	if (nb >= 10)
	{
		ft_printf_length(i, nb / 10, n);
		nb = nb % 10;
	}
	(*n)++;
	c = nb + 48;
	write(1, &c, 1);
	return (i + 2);
}
