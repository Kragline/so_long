NAME = so_long
CC = cc

CCFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx_Linux -lmlx_Linux -L ./minilibx-linux -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz

LIBFT = libft/libft.a

HEADER_DIR = include/
SRC_DIR = src/
OBJS_DIR = objs/

GNL_DIR = gnl/

FILENAMES = main keypress exit validation validation_utils
SRCS = $(addsuffix .c, $(addprefix $(SRC_DIR)ft_, $(FILENAMES)))
SRCS += gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS = $(addsuffix .o, $(addprefix $(OBJS_DIR)ft_, $(FILENAMES)))
OBJS += gnl/get_next_line.o gnl/get_next_line_utils.o

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(CCFLAGS) -I$(HEADER_DIR) -I$(GNL_DIR) $(LIBFT) $(OBJS) -o $(NAME) $(MLXFLAGS)

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	make -sC libft
	make -sC minilibx-linux
	mkdir -p $(OBJS_DIR)
	$(CC) -c $(CCFLAGS) -I$(HEADER_DIR) -Iminilibx-linux -I$(GNL_DIR) $< -o $@

clean:
	make -sC libft clean
	make -sC minilibx-linux clean
	rm -rf $(OBJS_DIR)

fclean: clean
	make -sC libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re