# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msamual <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 15:41:15 by msamual           #+#    #+#              #
#    Updated: 2020/08/12 19:58:58 by msamual          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
CC = gcc
SRCS = srcs/fill_map.c srcs/ft_reallock.c srcs/find_square.c srcs/main.c \
	   srcs/ft_atoi.c srcs/map_to_int_array.c srcs/ft_putchar.c
INC = includes
OBJ = $(SRCS:.c=.o)
FLAG = -Wall -Wextra -Werror

all: $(SRCS) $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAG) -I $(INC) -o $@

.c.o:
	$(CC) -c $(FLAG) -I $(INC) $< -o $@

clean:
	rm -f srcs/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
