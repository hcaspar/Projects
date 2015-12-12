#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/12 17:55:51 by hcaspar           #+#    #+#              #
#    Updated: 2015/12/12 18:09:49 by hcaspar          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME= fillit

SRC=	fillit.c	more.c

FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(FLAGS) -L. -lft -I. $(SRC)

clean:
	rm -f more.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all