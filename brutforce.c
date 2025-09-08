/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brutforce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nribakov <nribakov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:15:39 by nribakov          #+#    #+#             */
/*   Updated: 2025/09/08 21:49:15 by nribakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <stdlib.h>

void	reset_squeare(t_square *square, int row, int col);
void	update_biggest(t_square *biggest, t_square *current);

// Go throw full grid, trying to make a squer from each position
t_square	find_biggest_squer(t_map *m)
{
	int			row;
	int			col;
	t_square	biggest;
	t_square	current;

	row = 0;
	while (m->val[row] && row < m->height)
	{
		col = 0;
		while (m->val[row][col] && col < m->width)
		{
			reset_squeare(&current, row, col);
			current.size = find_square_max_size(current, m);
			update_biggest(&biggest, &current);
			col++;
		}
		row++;
	}
	return (biggest);
}

// Trying to make a squer on given position of max size
int	find_square_max_size(t_square square, t_map *map)
{
	int			current_size;
	int			new_size;
	t_square	new_square;

	current_size = square.size;
	new_size = current_size + 1;
	square.size = new_size;
	while (is_valid(&square, map))
	{
		current_size = square.size;
		new_size = current_size + 1;
		square.size = new_size;
	}
	return (current_size);
}

int	is_valid(t_square *square, t_map *map)
{
	if (square->size == 1)
	{
		return (map->val[square->row][square->col] == map->c_empty);
	}
	else
		return (is_right_side_valid(square, map) && is_bottom_side_valid(square,
				map));
}

// Square positioned within the map and there is no obstacles
int	is_right_side_valid(t_square *s, t_map *m)
{
	int	row;

	row = s->row;
	while (m->val[row][s->col + s->size - 1] && row < s->row + s->size)
	{
		if (m->val[row][s->col + s->size - 1] != m->c_empty)
			return (0);
		row++;
	}
	if (row < s->row + s->size)
		return (0);
	return (1);
}

// Square positioned within the map and there is no obstacles
int	is_bottom_side_valid(t_square *s, t_map *m)
{
	int	col;

	col = s->col;
	while (m->val[s->row + s->size - 1][col] && col < s->col + s->size)
	{
		if (m->val[s->row + s->size - 1][col] != m->c_empty)
			return (0);
		col++;
	}
	if (col < s->col + s->size)
		return (0);
	return (1);
}
