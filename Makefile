SHELL		=	/bin/bash

NAME		=	so_long

MLX			=	mlx_linux/
OBJ_DIR		=	obj/
HEADER		=	so_long.h

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
MLX_API		=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC			=	so_long.c set_data.c put_image.c mapping.c map_check.c key_hook.c check_limit.c
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

OBJF		=	.cache_exists

###################################

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJF)
		@make -C libft
		@cp libft/libft.a .
		@make -s -C $(MLX)
		@$(CC) $(CFLAGS) $(OBJ) libft.a $(MLX_API) -o $(NAME)

$(OBJ_DIR)%.o: %.c $(HEADER)| $(OBJF)
		@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR)
		@touch $(OBJF)

clean:
		@rm -rf $(OBJ_DIR)
		@make clean -C libft
		@rm -f $(OBJF)
		@make clean -C $(MLX)

fclean:	clean
		@rm -f $(NAME)
		@rm -f libft.a
		@rm -f libft/libft.a

re:		fclean all

.PHONY:	all clean fclean re