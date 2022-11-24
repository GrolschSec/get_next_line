NAME = libgnl.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c \
    get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	@echo "\033[0;33mGenerating obj..."
	$(CC) -c $(CFLAGS) $^
	@echo "\033[0m"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
