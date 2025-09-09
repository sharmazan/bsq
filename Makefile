NAME = bsq
CC = cc
CFLAGS += -g -Wall -Wextra -Werror

SOURCES = 	main.c \
			helper.c \
			parser.c \
			utils.c

TESTS = test_utils.c

UTILS = utils.c

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS)

# all: default

# re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJECTS)

tests:
	$(CC) -o test $(TESTS) $(UTILS)
	./test
	# rm -f ./test
