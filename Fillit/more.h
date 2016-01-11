/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:18:36 by hcaspar           #+#    #+#             */
/*   Updated: 2016/01/11 13:33:29 by hcaspar          ###   ########.fr       */
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
	int			s;
	int			end;
}				t_compt2;

void			ft_print_error(void);
void			ft_print_grid(char **grid);
void			ft_create_map(int size, char tab[size][5], int i);
t_compt2		ft_place(char **grid, int size, char tab[size][5], t_compt2 g);
t_compt2		ft_check(char **grid, int size, char tab[size][5], t_compt2 g);
t_compt2		ft_struct_init(t_compt2 g, int i);
t_compt2		loop_grid(t_compt2 g, char **grid);
t_compt2		loop_tab(t_compt2 g, int size, char tab[size][5]);
t_compt2		next_block(t_compt2 g);
t_compt2		prev_block(t_compt2 g, char **grid);
void			loop_erase(t_compt2 g, char **grid);

#endif
