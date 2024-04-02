GREEN = \033[0;32m
RESET = \033[0m
RED = \033[0;31m

SRCS_DIR = src
OBJS_DIR = obj

SRCS := $(shell find $(SRCS_DIR) -type f -name '*.c')
OBJS := $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
MLX = mlx/libmlx.a

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-w -g -fsanitize=address
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit
AR = ar rc

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MLX) -o $@

all: $(NAME) $(MLX) $(LIBFT)
	@echo "$(GREEN)FINISHED MAKING!$(RESET)"

$(MLX):
	@make -C mlx re

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)Cleaned$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Force cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re
