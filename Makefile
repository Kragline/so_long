NAME = so_long
CC = cc

CCFLAGS = -Wall -Wextra #-Werror
MLXFLAGS = -Lmlx_Linux -lmlx_Linux -L ./minilibx-linux -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz

LIBFT = libft/libft.a

HEADER_DIR = include/
SRC_DIR = src/

FILENAMES = main
SRCS = $(addsuffix .c, $(addprefix $(SRC_DIR)ft_, $(FILENAMES)))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(LIBFT) $(OBJS) -o $(NAME) $(MLXFLAGS)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	@make -sC libft
	@make -sC minilibx-linux
	$(CC) -c $(CCFLAGS) $(HEADER_DIR) -Iminilibx-linux $< -o $@

clean:
	@make -sC libft clean
	@make -sC minilibx-linux clean

fclean: clean
	@make -sC libft fclean
	rm -f $(NAME)
	rm -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re