#ifndef HEADER_H
# define HEADER_H

typedef struct square
{
	int		row;
	int		col;
	int		size;
}			t_square;

typedef struct map
{
	char	**val;
	int		width;
	int		height;
	char	c_empty;
	char	c_obstacle;
	char	c_full;
}			t_map;

#endif
