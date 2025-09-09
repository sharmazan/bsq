NAME = bsq
CFLAGS += -g -Wall -Wextra -Werror

SOURCES = 	main.c \
			helper.c \
			parser.c \
			utils.c

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	cc -o $(NAME) $(OBJECTS)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJECTS)
