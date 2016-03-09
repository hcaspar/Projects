/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_uni.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 04:23:15 by hcaspar           #+#    #+#             */
/*   Updated: 2016/03/07 23:48:36 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_char_uni(wint_t c, int i, int *n)
{
	write(1, &c, sizeof(wint_t));
	(*n)++;
	return (i + 1);
}
