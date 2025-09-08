struct			square
{
	int			row;
	int			col;
	int			size;
};

struct			map
{
	char		**val;
	int			width;
	int			hight;
	char		c_empty;
	char		c_obstacle;
	char		c_full;
};