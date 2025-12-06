#Customization: 
MAKEFLAGS += --no-print-directory		# to not display enerting the file while compiling
.RECIPEPREFIX = ~		# change the prefix from tab to ~
PINK_BOLD = \033[1;38;5;206m
END = \033[0m
GREEN = \033[38;5;71m
RED = \033[38;5;204m

#Essentials:
NAME = cub3d
CC = cc
LFLAGS = -LLibft -L../minilibx-linux -lft -lm -lmlx -lX11 -lXext
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
SRC = main.c checkers.c extract_data.c cleaning_service.c start_parsing.c init.c \
	map_validation.c
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LIBFT = libft.a
LIBFT_DIR = Libft

#Rules:

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) 
~@echo "$(GREEN)Compiling $(NAME)...$(END)"
~@echo "$(PINK_BOLD)DONE !$(END)"
~@$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
~@echo "$(GREEN)Creating object files...$(END)"
~@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
~@mkdir -p $(OBJ_DIR)

$(LIBFT):
~@echo "$(GREEN)Creating $(LIBFT)..."
~@make -C $(LIBFT_DIR)
~@make bonus -C $(LIBFT_DIR)

clean:
~@echo "$(RED)Deleting object files..."
~@rm -rf $(OBJ_DIR)
~@make clean -C $(LIBFT_DIR)

fclean: clean
~@echo "$(RED)Deleting $(NAME) and $(LIBFT)..."
~@rm -f $(NAME)
~@make fclean -C $(LIBFT_DIR)

re: fclean all

PHONY: all clean fclean re