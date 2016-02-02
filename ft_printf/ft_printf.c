/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:54:07 by hcaspar           #+#    #+#             */
/*   Updated: 2016/02/02 06:19:26 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	int		n;
	va_list	ap;

	i = 0;
	n = 0;
	va_start(ap, format);
	while (format[i])
	{
		j = i;
		while (format[i] && format[i] != '%')
			i++;
		write(1, &format[j], i - j);
		n = n + (i - j);
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				i = ft_printf_percent(i, &n);
			else if (format[i + 1] == 'n')
				i = ft_printf_length(i, n, &n);
			else if (format[i + 1] == 'c')
				i = ft_printf_char(va_arg(ap, int), i, &n);
			else if (format[i + 1] == 'd')
				i = ft_printf_int(va_arg(ap, int), i, &n);
			else if (format[i + 1] == 's')
				i = ft_printf_string(va_arg(ap, char*), i, &n);
		}
	}
	return (n);
}
