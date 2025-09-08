#include "bsq.h"
#include "header.h"
#include "helper.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int		fd;
	t_map	*map;
	int		error;

	error = 0;
	if (ac != 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(av[0]);
		ft_putstr(" <filename>\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error: Cannot open file ");
		ft_putstr(av[1]);
		ft_putstr("\n");
		return (1);
	}
	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_putstr("Error: Memory allocation failed\n");
		cleanup_resources(fd, map, 1);
	}
	if (!validate_map_file(fd, map))
	{
		ft_putstr("Error: Wrong map file\n");
		cleanup_resources(fd, map, 1);
	}
	else
	{
		ft_putstr("Good map file\n");
	}
	// if (read_line(fd, config, sizeof(config)) != NULL)
	// {
	// 	if (parse_config(config, map))
	// 	{
	// 		// Successfully parsed config
	// 	}
	// 	else
	// 	{
	// 		ft_putstr("Error: Invalid config line in file ");
	// 		ft_putstr(av[1]);
	// 	}
	// }
	// else
	// {
	// 	ft_putstr("Error: Cannot read config line from file ");
	// 	ft_putstr(av[1]);
	// 	ft_putstr("\n");
	// 	close(fd);
	// 	return (1);
	// }
	close(fd);
	return (0);
}
