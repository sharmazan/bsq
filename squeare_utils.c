#include <header.h>

// Squer: initial size 0 - if satys 0, squer is not posible on this position
void	reset_squeare(t_square *square, int row, int col)
{
	square->row = row;
	square->col = col;
	square->size = 0;
}

// If new square is bigger then currrent, set values of new to bigger
void	update_biggest(t_square *biggest, t_square *current)
{
	if (current->size > biggest->size)
	{
		biggest->row = current->row;
		biggest->col = current->col;
		biggest->size = current->size;
	}
}

int	is_square_area(t_square *s, int row, int col)
{
	return ((row >= s->row && row <= s->row + s->size) &&
		(col >= s->col && col <= s->col + s->size));
}