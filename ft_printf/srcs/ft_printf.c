/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:54:07 by hcaspar           #+#    #+#             */
/*   Updated: 2016/03/07 23:48:17 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf_get_num(const char *format, int *i)
{
	int		j;
	int		width;
	int		str_width;
	char	*str;

	str_width = (*i);
	while (format[str_width] >= '0' && format[str_width] <= '9')
		str_width++;
	str = (char*)malloc(sizeof(char) * ((str_width - (*i)) + 1));
	str_width = 0;
	while (format[(*i)] >= '0' && format[(*i)] <= '9')
	{
		str[str_width] = format[(*i)];
		(*i)++;
		str_width++;
	}
	str[str_width] = '\0';
	j = 0;
	width = 0;
	while (str[j])
	{
		width = width * 10 + str[j] - 48;
		j++;
	}
	return (width);
}

int			ft_printf_details(const char *format, int i, t_struct *details)
{
	if (format[i] == '-' || format[i] == '+' || format[i] == ' ' ||	\
		format[i] == '#' || format[i] == '0')
		details->flag = format[i++];
	if (format[i] >= '0' && format[i] <= '9')
		details->width = ft_printf_get_num(format, &i);
	if (format[i] == '.')
	{
		i++;
		details->precision = ft_printf_get_num(format, &i);
	}
	return (i);
}

int			ft_printf(const char *format, ...)
{
	int			i;
	int			j;
	int			n;
	int			d;
	char		*s;
	va_list		ap;
	t_struct	*details;

	i = 0;
	n = 0;
	details = (t_struct*)malloc(sizeof(t_struct));
	va_start(ap, format);
	while (format[i])
	{
		details->precision = -1;
		details->width = 0;
		details->flag = 0;
		j = i;
		while (format[i] && format[i] != '%')
			i++;
		write(1, &format[j], i - j);
		n = n + (i - j);
		if (format[i] == '%')
		{
			i =	ft_printf_details(format, i + 1, details);
			details->conv = format[i];
			if (format[i] == '%')
			{
				if (details->flag == 0 || details->flag == '0')
					n = ft_printf_pad(1, n, details);
				i = ft_printf_percent(i, &n);
				if (details->flag == '-')
					n = ft_printf_pad(1, n, details);
			}
			if (format[i] == 'n')
				i = ft_printf_length(i, n, &n);
			if (format[i] == 'c')
				i = ft_printf_char(va_arg(ap, int), i, &n);
			if (format[i] == 'C')
				i = ft_printf_char_uni(va_arg(ap, wint_t), i, &n);
			if (format[i] == 'd' || format[i] == 'x' ||\
				format[i] == 'o' || format[i] == 'X')
			{
				d = va_arg(ap, int);
				if (details->flag == 0 || details->flag == '0')
					n = ft_printf_pad(d, n, details);
				i = ft_printf_int(d, i, &n, details);
				if (details->flag == '-')
					n = ft_printf_pad(d, n, details);
			}
			if (format[i] == 's')
			{
				s = va_arg(ap, char*);
				if (details->flag == 0 || details->flag == '0')
					n = ft_printf_pad_string(s, n, details);
				i = ft_printf_string(s, i, &n, details);
				if (details->flag == '-')
					n = ft_printf_pad_string(s, n, details);
			}
			if (format[i] == 'S')
			{
				
			}
			if (format[i] == 'p')
				i = ft_printf_hexa(va_arg(ap, void*), i, 1);
		}
	}
	free(details);
	return (n);
}
