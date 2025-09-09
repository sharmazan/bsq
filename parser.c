#include "header.h"
#include "helper.h"
#include "utils.h"
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

	if (read_line_to_buffer(fd, config, sizeof(config)) == NULL)
		return (0);
	if (!(height = parse_config_line(config, m)))
		return (0);
	i = 0;
	while (i < height)
	{
		line_len = 0;
		while (read(fd, &c, 1))
		{
			if (c == '\n')
				break ;
			line_len++;
		}
		if (i == 0)
			width = line_len;
		else if (line_len != width)
			return (0);
		i++;
	}
	m->width = width;
	return (width);
}

int	parse_config_line(char *config, t_map *m)
{
	int				i;
	unsigned int	height;

	i = 0;
	height = 0;
	while (config[i] >= '0' && config[i] <= '9')
	{
		height = height * 10 + (config[i] - '0');
		i++;
	}
	if (height == 0 || ft_strlen(config) - i < 3)
		return (0);
	m->height = height;
	m->c_empty = config[i++];
	m->c_obstacle = config[i++];
	m->c_full = config[i++];
	return (height);
}
