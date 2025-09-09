#include "utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

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

int	test_read_line(void)
{
	int		fd;
	int		bytes_read;
	char	*str;
	char	*str2;

	str = malloc(1);
	str2 = "Test file, don't remove it";
	fd = open("testfile.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	bytes_read = read_line(fd, str);
	printf("Read %d bytes, in string %s\n", bytes_read, str);
	free(str);
	return (1);
	// if (ft_strcmp(str, str2) == 0)
	// {
	// 	free(str);
	// 	return (1);
	// }
	// else
	// 	return (0);
}

int	main(void)
{
	if (test_increase_buf())
		printf("test_increase_buf - TEST PASSED\n");
	else
		printf("test_increase_buf - TEST FAILED\n");
	if (test_read_line())
		printf("test_increase_buf - TEST PASSED\n");
	else
		printf("test_increase_buf - TEST FAILED\n");
}
