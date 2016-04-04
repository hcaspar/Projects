/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:48:17 by hcaspar           #+#    #+#             */
/*   Updated: 2016/04/04 22:39:49 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <stdio.h>
#include <locale.h>

int			main(void)
{
	char	*s;
	int		d;
	wint_t	t;
	void	*p;
	wchar_t	*u;

	d = 18;
	p = &t;
	u = L"لحم خنزير";
	t = L'ل';
	s = "je suis bon";
	setlocale(LC_CTYPE, "");
	d = printf("1:%d\n", 42);
	printf("%d\n", d);
	d = ft_printf("2:%d\n", 42);
	printf("%d\n", d);
	return (0);
}
