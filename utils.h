#ifndef UTILS_H
# define UTILS_H

void	ft_putstr(char *str);
void	ft_putchar(char c);
char	*increase_buf(char *buf, unsigned int increase);
void	copy_nbytes(char *dst, const char *src, int n);
int		read_line(int fd, char *buffer);
char	*read_line_to_buffer(int fd, char *buffer, int buffer_size);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
#endif
