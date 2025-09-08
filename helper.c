#include "header.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	validate_map_file(int fd, t_map *m)
{
	int		i;
	int		line_len;
	int		height;
	int		width;
	char	c;
	char	config[100];
	ssize_t	bytes_read;

	if (read_line(fd, config, sizeof(config)) == NULL)
		return (0);
	printf("read_line works\n");
	if (!(height = parse_config_line(config, m)))
		return (0);
	printf("parse_config_line works\n");
	i = 0;
	while (i < height)
	{
		line_len = 0;
		bytes_read = read(fd, &c, 1);
		while (bytes_read == 1)
		{
			if (c == '\n')
				break ;
			bytes_read = read(fd, &c, 1);
		}
		if (i == 0)
			width = line_len;
		else if (line_len != width)
			return (0);
		i++;
	}
	return (width);
}

// int	read_map_from_file(int fd, t_map *m)
// {
// 	char	*line;

// 	line = malloc(100);
// 	if (read_line(fd, config, sizeof(config)) != NULL)
// 	{
// 		if (parse_config(config, m))
// 		{
// 			// Successfully parsed config
// 		}
// 		else
// 		{
// 			ft_putstr("Error: Invalid config line in file ");
// 			ft_putstr(av[1]);
// 		}
// 	}
// 	return (1);
// }

void	cleanup_resources(int fd, t_map *m, int exit_code)
{
	if (m)
	{
		free(m);
	}
	if (fd != -1)
	{
		close(fd);
	}
	exit(exit_code);
}
