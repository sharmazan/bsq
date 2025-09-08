bsq:
	cc -g -Wall -Wextra -Werror -o bsq *.c

fclean:
	rm -f *.o* bsq
