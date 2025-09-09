#ifndef HELPER_H
# define HELPER_H

void	cleanup_resources(int fd, t_map *m, int exit_code);
int		parse_config_line(char *config, t_map *m);
int		validate_map_file(int fd, t_map *m);
#endif
