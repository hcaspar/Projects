/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:18:36 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/20 18:10:51 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MORE_H
# define MORE_H

# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct	s_compt
{
	int			i;
	int			j;
}				t_compt;

typedef struct	s_compt2
{
	int			i;
	int			j;
	int			i2;
	int			j2;
	char		c;
	int			b;
}				t_compt2;

void			ft_print_error(void);
void			ft_print_tab(int size, char tab[size][5]);
void			ft_create_map(int size, char tab[size][5], int i);
int				ft_place(char **grid, int size, char tab[size][5], t_compt2 g);

#endif
