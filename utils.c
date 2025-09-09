#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	copy_nbytes(char *dst, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

char	*increase_buf(char *buf, unsigned int increase)
{
	int		i;
	int		len;
	char	*new_buf;

	len = ft_strlen(buf);
	new_buf = malloc(sizeof(char) * len + increase + 1);
	if (new_buf != NULL)
	{
		copy_nbytes(new_buf, buf, len);
		free(buf);
		buf = new_buf;
	}
	return (new_buf);
}

char	*read_line(int fd, char *buffer, int buffer_size)
{
	int		i;
	char	c;
	ssize_t	bytes_read;

	i = 0;
	while (i < buffer_size - 1)
	{
		bytes_read = read(fd, &c, 1);
		if (bytes_read <= 0 || c == '\n')
			break ;
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	// printf("bytes_read: %zu\n", bytes_read);
	return ((i > 0 || bytes_read > 0) ? buffer : NULL);
}
