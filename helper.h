#ifndef HELPER_H
# define HELPER_H

void	ft_putstr(char *str);
void	ft_putchar(char c);
char	*read_line(int fd, char *buffer, int buffer_size);
void	cleanup_resources(int fd, t_map *m, int exit_code);
int		parse_config_line(char *config, t_map *m);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		validate_map_file(int fd, t_map *m);
#endif
