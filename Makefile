NAME = so_long
CC = cc

CCFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx_Linux -lmlx_Linux -L ./minilibx-linux -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz

LIBFT = libft/libft.a

HEADER_DIR = include/
SRC_DIR = src/
OBJS_DIR = objs/

FILENAMES = main keypress exit validation validation_utils utils free clear_textures\
			check_path draw init_textures render game_over get_next_line get_next_line_utils
SRCS = $(addsuffix .c, $(addprefix $(SRC_DIR), $(FILENAMES)))
OBJS = $(addsuffix .o, $(addprefix $(OBJS_DIR), $(FILENAMES)))

all: $(NAME)

$(NAME): $(OBJS) Makefile
	@$(CC) $(CCFLAGS) -I$(HEADER_DIR) $(LIBFT) $(OBJS) -o $(NAME) $(MLXFLAGS)

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@make -sC libft
	@mkdir -p $(OBJS_DIR)
	@$(CC) -c $(CCFLAGS) -I$(HEADER_DIR) -Iminilibx-linux $< -o $@

clean:
	@make -sC libft clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re