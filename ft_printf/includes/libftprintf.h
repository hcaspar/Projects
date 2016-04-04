/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:41:25 by hcaspar           #+#    #+#             */
/*   Updated: 2016/04/04 22:36:22 by hcaspar          ###   ########.fr       */
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
	int			point;
	int			n;
	int			diese;
	int			plus;
	int			minus;
	int			space;
	int			zero;
	int			noflag;
	int			mod;
	char		conv;
	int			width;
	int			precision;
	int			digit;
	int			sign;
	unsigned \
	long \
	long		base;
}				t_struct;

int				ft_printf(const char *format, ...);
int				ft_count_digit(int pad, t_struct *details, int v);
int				ft_count_int(unsigned long long d, t_struct *details, int pad);
int				ft_count_hex(unsigned long long d, t_struct *details, int pad);
void			ft_casts(void *d, t_struct *details);
void			ft_conv_c(int c, t_struct *details);
void			ft_conv_c_uni(wint_t c, t_struct *details);
void			ft_conv_s(char *s, t_struct *details);
void			ft_conv_s_uni(wchar_t *s, t_struct *details);
void			ft_conv_d(long long d, t_struct *details);
void			ft_conv_u(unsigned long long d, t_struct *details);
void			ft_conv_hex(unsigned long long d, t_struct *details);
void			ft_conv_percent(t_struct *details);
void			ft_printf_width(void *d, t_struct *details);
void			ft_printf_percent(t_struct *details);
void			ft_printf_length(int nb, t_struct *details);
void			ft_printf_int(unsigned long long d, t_struct *details, int v, \
							int pad);
void			ft_printf_hex(unsigned long long d, t_struct *details, int v, \
							int pad);
void			ft_printf_u(unsigned long long d, t_struct *details, int v, \
							int pad);
void			ft_printf_char(int c, t_struct *details);
void			ft_printf_char_uni(wint_t c, t_struct *details);
void			ft_printf_string(char *s, t_struct *details);
void			ft_printf_string_uni(wchar_t *s, t_struct *details);
void			ft_printf_pad(t_struct *details, int power);
void			ft_printf_pad_string(char *s, t_struct *details);
void			ft_printf_pad_string_uni(wchar_t *s, t_struct *details);
int				ft_noconv(t_struct *details);
void			ft_conv_porn(t_struct *details);

#endif
