/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 04:23:15 by hcaspar           #+#    #+#             */
/*   Updated: 2016/04/04 21:05:24 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_four_bytes(unsigned int value, t_struct *details)
{
	unsigned char	octet;

	octet = 240 + (value >> 18);
	write(1, &octet, 1);
	octet = 128 + ((value >> 12) & 63);
	write(1, &octet, 1);
	octet = 128 + ((value >> 6) & 63);
	write(1, &octet, 1);
	octet = 128 + (value & 63);
	write(1, &octet, 1);
	details->n = details->n + 4;
}

static void	print_three_bytes(unsigned int value, t_struct *details)
{
	unsigned char	octet;

	octet = 224 + (value >> 12);
	write(1, &octet, 1);
	octet = 128 + ((value >> 6) & 63);
	write(1, &octet, 1);
	octet = 128 + (value & 63);
	write(1, &octet, 1);
	details->n = details->n + 3;
}

static void	print_two_bytes(unsigned int value, t_struct *details)
{
	unsigned char	octet;

	octet = 192 + (value >> 6);
	write(1, &octet, 1);
	octet = 128 + (value & 63);
	write(1, &octet, 1);
	details->n = details->n + 2;
}

void		ft_printf_char_uni(wint_t c, t_struct *details)
{
	unsigned int	value;

	value = (unsigned int)c;
	if (value <= 127)
	{
		write(1, &value, 1);
		details->n++;
	}
	else if (value < 2048)
		print_two_bytes(value, details);
	else if (value < 65536)
		print_three_bytes(value, details);
	else
		print_four_bytes(value, details);
}

void		ft_printf_char(int c, t_struct *details)
{
	write(1, &c, 1);
	details->n++;
}
