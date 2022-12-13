NAME	=	a.out

#
# SRCS and OBJS
#

SRCS	=	/mlx

OBJS = $(SRCS:%.c=%.o)

#
# Compiler and flags
#

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

#
# Rules
#

all		: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re:	fclean all

.PHONY: all clean fclean re