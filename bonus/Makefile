# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 18:15:16 by ramhouch          #+#    #+#              #
#    Updated: 2022/11/26 22:20:26 by ramhouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=so_long
FLAGS = -lmlx -framework OpenGL -framework AppKit
CFLAGS=-Wall -Wextra -Werror 
SRC = main.c putstr.c strlen.c map.c get_next_line.c get_next_line_utils.c new_view.c moves.c putnbr.c check.c path_is_valid.c itoa.c enemys.c freetabe.c messages.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
		cc -o $(NAME) $(OBJ) $(FLAGS)

clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re bonus
