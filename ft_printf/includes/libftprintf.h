/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:41:25 by hcaspar           #+#    #+#             */
/*   Updated: 2016/02/02 06:26:58 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>

int			ft_printf_percent(int i, int *n);
int			ft_printf_length(int i, int nb, int *n);
int			ft_printf_int(int d, int i, int *n);
int			ft_printf_char(char c, int i, int *n);
int			ft_printf_string(char *s, int i, int *n);

#endif
