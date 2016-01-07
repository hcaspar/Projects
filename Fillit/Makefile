#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/12 17:55:51 by hcaspar           #+#    #+#              #
#    Updated: 2016/01/07 16:06:07 by hcaspar          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME= fillit

CC = gcc

SRC=	fillit.c	more.c		even_more.c		just_one_more.c

CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(CFLAGS) -L. -lft -I. $(SRC)

clean:
	rm -f more.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all