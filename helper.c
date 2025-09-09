#include "header.h"
#include "helper.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// int	read_map_from_file(int fd, t_map *m)
// {
// 	// char	*line;
// 	// line = malloc(100);
// 	// if (read_line(fd, config, sizeof(config)) != NULL)
// 	// {
// 	// 	if (parse_config(config, m))
// 	// 	{
// 	// 		// Successfully parsed config
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		ft_putstr("Error: Invalid config line in file ");
// 	// 		ft_putstr(av[1]);
// 	// 	}
// 	// }
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
