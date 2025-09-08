#include "header.h"
#include "helper.h"

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
