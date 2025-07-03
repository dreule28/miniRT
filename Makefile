NAME = miniRT
CC = cc
RM = rm -rf

################################################################################
###############                  DIRECTORIES                      ##############
################################################################################

OBJ_DIR = _obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIRS := Includes $(LIBFT_DIR)
SRC_DIRS := src
HEADERS = -I $(LIBFT_DIR)/include -I $(MLX42_DIR)/include/MLX42
MLX42_DIR = MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
LIBS = $(MLX42_LIB) $(LIBFT) -ldl -pthread -lm -lglfw

vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

################################################################################
###############                  SOURCE FILES                     ##############
################################################################################

MATRICES_FILES := add_col.c cmp_col.c init_matrices.c m_cmp.c matrix_multi.c transpose_matrix.c determinant.c m3_sub_matrix.c m4_sub_matrix.c cofo.c inversion.c transformation.c rotate_matrix.c rotate_tuples.c shearing.c
MATRICES := $(addprefix math_ops/matrices/, $(MATRICES_FILES))

TUPLES_FILES := tuples_func.c more_tuples_func.c tup_func.c custom_math_func.c
TUPLES := $(addprefix math_ops/tuples/, $(TUPLES_FILES))

# RAY_TRACING_FILES := ray_tracing.c custom_mlx_func.c projectile.c keyboard_hooks.c custom_math_func.c
# RAY_TRACING := $(addprefix ray_tracing/, $(RAY_TRACING_FILES))

PARSER_FILES := fill_elements.c fill_objects.c initialize_objects.c list_and_nodes.c parser.c inits.c
PARSER := $(addprefix parser/, $(PARSER_FILES))

SRC_FILES := main.c debug.c
SRC := $(addprefix src/, $(SRC_FILES)  $(MATRICES) $(TUPLES) $(PARSER))

################################################################################
###############               OBJECT FILES & RULES                ##############
################################################################################

OBJS := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flags and linking options
CFLAGS := -Wall -Wextra -Werror -g -IIncludes -Ilibft -I$(MLX42_DIR)/include/MLX42 -MMD -MP $(addprefix -I, $(INC_DIRS))
LDFLAGS := -Llibft -lft  -lreadline -lncurses
CFLAGS_SAN := $(CFLAGS) -fsanitize=address -g
LDFLAGS_SAN := $(LDFLAGS) -fsanitize=address

# Color definitions for better terminal output
COLOR_RESET = \033[0m
COLOR_GREEN = \033[0;32m
COLOR_BLUE = \033[0;34m
COLOR_CYAN = \033[0;36m

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42_LIB) $(OBJS)
	@echo "$(COLOR_GREEN)Creating $(NAME)...$(COLOR_RESET)"
	@$(CC) $(OBJS) -o $(NAME) $(LIBS) $(LDFLAGS)
	@echo "$(COLOR_GREEN)Successful Compilation of $(NAME)$(COLOR_RESET)"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@echo "$(COLOR_GREEN)Compiling $<...$(COLOR_RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "$(COLOR_GREEN)Compiling libft..$(COLOR_RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX42_LIB):
	@if [ ! -d "$(MLX42_DIR)" ]; then \
		echo "Cloning MLX42..."; \
		git clone https://github.com/codam-coding-college/MLX42.git; \
	fi
	@if [ ! -f "$(MLX42_LIB)" ]; then \
		echo "$(COLOR_GREEN)Building MLX42...$(COLOR_RESET)"; \
		cmake $(MLX42_DIR) -B $(MLX42_DIR)/build; \
		make -C $(MLX42_DIR)/build -j4; \
	fi
	@echo "$(COLOR_GREEN)MLX42 ready$(COLOR_RESET)"

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@echo "$(COLOR_GREEN)Cleaning object files...$(COLOR_RESET)"
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(COLOR_GREEN)Removing $(NAME)...$(COLOR_RESET)"
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(COLOR_GREEN)Removed files successfully$(COLOR_RESET)"

re: fclean all

help:
	@echo "Available targets:"
	@echo "  all      - Build miniRT (default)"
	@echo "  clean    - Remove object files"
	@echo "  fclean   - Remove all generated files"
	@echo "  re       - Rebuild miniRT"

.PHONY: all clean fclean re help