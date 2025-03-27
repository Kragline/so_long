NAME = so_long
CC = cc

CCFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx_Linux -lmlx_Linux -L ./minilibx-linux -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz

LIBFT = libft/libft.a

HEADER_DIR = include/
SRC_DIR = src/
OBJS_DIR = objs/

GNL_DIR = gnl/
GNL = gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_OBJS = objs/get_next_line.o objs/get_next_line_utils.o

FILENAMES = main keypress exit validation validation_utils utils free \
			check_path draw
SRCS = $(addsuffix .c, $(addprefix $(SRC_DIR)ft_, $(FILENAMES)))
OBJS = $(addsuffix .o, $(addprefix $(OBJS_DIR)ft_, $(FILENAMES)))

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) Makefile
	$(CC) $(CCFLAGS) -I$(HEADER_DIR) -I$(GNL_DIR) $(LIBFT) $(OBJS) $(GNL_OBJS) -o $(NAME) $(MLXFLAGS)

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	make -sC libft
	make -sC minilibx-linux
	mkdir -p $(OBJS_DIR)
	$(CC) -c $(CCFLAGS) -I$(HEADER_DIR) -Iminilibx-linux $< -o $@

$(OBJS_DIR)%.o: $(GNL_DIR)%.c
	$(CC) -c $(CCFLAGS) -I$(GNL_DIR) -Iminilibx-linux $< -o $@

clean:
	make -sC libft clean
	make -sC minilibx-linux clean
	rm -rf $(OBJS_DIR)

fclean: clean
	make -sC libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re