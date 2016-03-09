/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:41:25 by hcaspar           #+#    #+#             */
/*   Updated: 2016/02/22 22:48:52 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

typedef	struct	s_struct
{
	char		conv;
	char		flag;
	int			width;
	int			precision;
}				t_struct;

int				ft_printf(const char *format, ...);
int				ft_printf_percent(int i, int *n);
int				ft_printf_length(int i, int nb, int *n);
int				ft_printf_int(int d, int i, int *n, t_struct *details);
int				ft_printf_char(int c, int i, int *n);
int				ft_printf_char_uni(int c, int i, int *n);
int				ft_printf_string(char *s, int i, int *n, t_struct *details);
int				ft_printf_pad(int d, int n, t_struct *details);
int				ft_printf_pad_string(char *s, int n, t_struct *details);
int				ft_printf_hexa(void *addr, int i, int x);

#endif
