/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:48:17 by hcaspar           #+#    #+#             */
/*   Updated: 2016/03/07 23:48:18 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <stdio.h>
#include <locale.h>

int			main(void)
{
	char	c;
	char	*s;
	int		d;
	wint_t	t;
	void	*p;

	c = 'b';
	d = 10;
	p = &c;
	t = L'繁';
	s = "je suis bon";
	setlocale(LC_CTYPE, "");
	printf("%C\n", t);
	ft_printf("%C\n", t);
	return (0);
}
