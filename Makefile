NAME	=	so_long
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
MLXFLAG =	-lmlx -lXext -lX11
DEBUG	= 	-fsanitize=address -static-libasan -g

SRC		=	src/so_long.c src/generate_map.c \
			utils/map_check.c utils/map_read.c utils/error.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ_DIR =	obj
OBJ		=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(OBJ) $(MLXFLAG) -g ./libft/libft.a -o $(NAME)

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
