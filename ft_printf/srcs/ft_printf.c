/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:54:07 by hcaspar           #+#    #+#             */
/*   Updated: 2016/04/04 22:32:09 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_printf_get_num(const char *format, int *i)
{
	int			j;
	int			width;
	int			str_width;
	char		*str;

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

static int		ft_get_mod(const char *format, int i, t_struct *details)
{
	while (format[i] == 'h' || format[i] == 'l' || format[i] == 'j'\
			|| format[i] == 'z')
	{
		if (format[i] == 'h' && format[i + 1] == 'h' && (i = i + 2))
			details->mod = 'h' + 'h';
		else if (format[i] == 'h' && ++i)
			details->mod = 'h';
		else if (format[i] == 'l' && format[i + 1] == 'l' && (i = i + 2))
			details->mod = 'l' + 'l';
		else if (format[i] == 'l' && ++i)
			details->mod = 'l';
		else if (format[i] == 'j' && ++i)
			details->mod = 'j';
		else if (format[i] == 'z' && ++i)
			details->mod = 'z';
	}
	return (i);
}

static int		ft_details(const char *format, int i, t_struct *details)
{
	while (format[i] == '-' || format[i] == '+' || format[i] == ' ' || \
			format[i] == '#' || format[i] == '0')
	{
		details->noflag = 0;
		if (format[i] == '-' && ++i)
			details->minus = 1;
		if (format[i] == '+' && ++i)
			details->plus = 1;
		if (format[i] == ' ' && ++i)
			details->space = 1;
		if (format[i] == '#' && ++i)
			details->diese = 1;
		if (format[i] == '0' && ++i && !details->minus)
			details->zero = 1;
	}
	if (format[i] >= '0' && format[i] <= '9')
		details->width = ft_printf_get_num(format, &i);
	if (format[i] == '.' && ++i)
		details->precision = ft_printf_get_num(format, &i);
	i = ft_get_mod(format, i, details);
	return (i);
}

static int		ft_init(const char *format, int i, t_struct *details)
{
	int			j;

	details->diese = 0;
	details->plus = 0;
	details->minus = 0;
	details->space = 0;
	details->zero = 0;
	details->noflag = 1;
	details->mod = 0;
	details->width = 0;
	details->precision = -1;
	details->point = 0;
	details->sign = 0;
	details->digit = 0;
	details->base = 16;
	j = i;
	while (format[i] && format[i] != '%')
		i++;
	write(1, &format[j], i - j);
	details->n = details->n + (i - j);
	return (i);
}

int				ft_printf(const char *format, ...)
{
	int			i;
	int			n;
	va_list		ap;
	t_struct	*details;

	i = 0;
	details = (t_struct*)malloc(sizeof(t_struct));
	details->n = 0;
	va_start(ap, format);
	while (format[i])
	{
		i = ft_init(format, i, details);
		if (format[i] == '%')
		{
			i = ft_details(format, i + 1, details);
			details->conv = format[i];
			if ((format[i] == '%' || format[i] == 'n') && ++i)
				ft_conv_porn(details);
			else if (format[i] != '\0' && ++i && ft_noconv(details))
				ft_casts(va_arg(ap, void*), details);
		}
	}
	n = details->n;
	free(details);
	return (n);
}
