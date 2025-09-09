#include <stdio.h>
#include <stdlib.h>

char	*increase_buf(char *buf, unsigned int increase);
void	copy_nbytes(char *dst, const char *src, int n);

int	test_increase_buf(void)
{
	char	*str;
	char	*new_str;

	new_str = "0123456789";
	str = malloc(1);
	str[0] = 0;
	str = increase_buf(str, 10);
	copy_nbytes(str, new_str, 10);
	if (str[9] == '9')
	{
		free(str);
		return (1);
	}
	else
		return (0);
}

int	main(void)
{
	if (test_increase_buf())
		printf("test_increase_buf - TEST PASSED\n");
	else
		printf("test_increase_buf - TEST FAILED\n");
}
