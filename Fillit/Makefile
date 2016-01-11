#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/12 17:55:51 by hcaspar           #+#    #+#              #
#    Updated: 2016/01/11 13:52:45 by hcaspar          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

CC = gcc

SRC =	fillit.c	more.c		even_more.c		last_one.c

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(CFLAGS) -L. -lft -I. $(OBJ)

debug:
	gcc -o $(NAME) -L. -lft -I. $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
