/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 20:03:09 by hcaspar           #+#    #+#             */
/*   Updated: 2016/03/07 18:55:24 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf_hexa(void *addr, int i, int x)
{
	long	q;

	q = (long)addr;
	if (x == 1)
		write(1, "0x", 2);
	if (q > 15)
	{
		ft_printf_hexa((void*)(q / 16), i, 0);
		q = q % 16;
	}
	if (q >= 10)
		q = q + 39;
	q = q + 48;
	write(1, &q, 1);
	return (i + 1);
}
