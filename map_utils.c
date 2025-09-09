#include <header.h>

int	is_square_area(t_square *s, int row, int col);

void draw_squer(t_map *m, t_square *s)
{
	int			row;
	int			col;

	row = 0;
	while (m->val[row] && row < m->height)
	{
		col = 0;
		while (m->val[row][col] && col < m->width)
		{
			if(is_square_area(s, row, col))
				m->val[row][col] = m->c_full;
			col++;
		}
		row++;
	}
}
void print_map(t_map map)
{

}