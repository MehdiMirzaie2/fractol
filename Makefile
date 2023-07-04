# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:29:13 by mmirzaie          #+#    #+#              #
#    Updated: 2023/07/04 23:10:11 by mehdimirzai      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RESET = \033[0m
RED = \033[0;31m

SRCS = $(wildcard src/*.c)
MLX = mlx/libmlx.a
# LIBFT = libft/libft.a

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -w -g -fsanitize=address
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit
AR = ar rc

OBJS = $(SRCS:.c=.o)

%.o : %.c
	@ $(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME) $(MLX) $(LIBFT)
	@ echo "$(GREEN)FINISHED MAKING!$(RESET)"

$(MLX):
	@make -C mlx/ re

# $(LIBFT):
    # @make -C libft/ re

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@ echo "$(RED)Cleaned$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@ echo "$(RED)Force cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re
