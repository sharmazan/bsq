#include <header.h>

t_square	find_biggest_squer(t_map *m);

void solve(t_map *map)
{
	t_square square = find_biggest_squer(map);
	draw_squer(map, square);
	print_map(map);
}