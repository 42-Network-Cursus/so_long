# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwastche <cwastche@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 22:22:24 by cwastche          #+#    #+#              #
#    Updated: 2022/01/30 22:22:30 by cwastche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
MLXFLAG =	-lmlx -lXext -lX11

SRC		=	src/so_long.c src/generate_map.c src/map_check.c src/map_read.c\
			utils/error.c utils/moves.c\
			gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ_DIR =	obj
OBJ		=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(OBJ) $(MLXFLAG) ./libft/libft.a -o $(NAME)

$(OBJ_DIR)/%.o	:	%.c
	mkdir -p $(OBJ_DIR) $(OBJ_DIR)/src $(OBJ_DIR)/utils $(OBJ_DIR)/gnl
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean	:
	$(MAKE) -C ./libft fclean
	rm -rf $(OBJ) $(OBJ_DIR)

fclean	:	clean
	rm -rf $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
