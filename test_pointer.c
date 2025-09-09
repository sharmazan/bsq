#include <stdio.h>

int	change_pointer_local(char *pointer)
{
	pointer++;
	return (0);
}

int	change_pointer_outside(char **pointer)
{
	*(pointer)++ = *(pointer) + 1;
	return (0);
}

int	main(void)
{
	char	*ptr;

	ptr = "123";
	printf("%s\n", ptr);
	change_pointer_local(ptr);
	printf("%s\n", ptr);
	change_pointer_outside(&ptr);
	printf("%s\n", ptr);
}
