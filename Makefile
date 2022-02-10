NAME = so_long

SRCS = functions/ft_strcmp.c \
	   functions/ft_itoa.c \
	   functions/ft_bzero.c \
	   functions/ft_putstr_fd.c \
	   functions/get_next_line.c \
	   functions/get_next_line_utils.c \
	   utils/check_0.c \
	   utils/check_1.c \
	   utils/check.c \
	   utils/geters.c \
	   src/launch.c \
	   src/moves.c \
	   src/put_images.c \
	   src/help_images.c \
	   src/so_long.c \

CC = gcc

OBJS	= 	$(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

MLX_HEADER = /usr/local/include

RM = rm -rf

HEADER = ./includes/so_long.h

MAKE = make

all: $(NAME)

$(NAME): $(OBJS)
		@${CC} ${FLAGS} -I ${MLX_HEADER} $(SRCS) ${MLX_FLAGS} -o ${NAME}
		@echo "\033[92mSO_LONG IS READY :)\033[0m"

.c.o:
	@$(CC) $(FLAGS) -I $(HEADER) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@${RM} ${NAME}
	@echo "\033[32mSO_LONG IS DELETED *-_-*\033[0m"

re: fclean all

.PHONY: all clean fclean re
