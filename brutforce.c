/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brutforce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nribakov <nribakov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:15:39 by nribakov          #+#    #+#             */
/*   Updated: 2025/09/08 19:57:45 by nribakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <stdlib.h>

// Squer: initial size 0 - if satys 0, squer is not posible on this position
struct square	init_squeare(int row, int col)
{
	struct square	new_square;

	new_square.col = col;
	new_square.row = row;
	new_square.size = 0;
	retunr(new_square);
}

// Go throw full grid, trying to make a squer from each position
struct square	*find_bigges_squer(struct map map)
{
	int				row;
	int				col;
	struct square	*bigges;

	struct square *current; // make correct from reference prespective
	bigges = current;
	row = 0;
	while (map.val[row] && row < map.hight)
	{
		col = 0;
		while (map.val[row][col] && col < map.width)
		{
			current = init_squeare(row, col);
			current->size = find_square_max_size(current, map);
			bigges = get_bigges(bigges, current);
			col++;
		}
		row++;
	}
	return (0);
}
// Trying to make a squer on given position of max size
int	find_square_max_size(struct square square, struct map map)
{
	int				current_size;
	int				new_size;
	struct square	new_square;

	current_size = square.size;
	new_size = current_size + 1;
	square.size = new_size;
	while (is_valid(square, map))
	{
		current_size = square.size;
		new_size = current_size + 1;
		square.size = new_size;
	}
	return (current_size);
}

int	is_valid(struct square square, struct map map)
{
	int	row;
	int	col;

	if (square.size == 1)
	{
		return (map.val[square.row][square.col] == map.c_empty);
	}
	row = square.row;
	col = square.col;
	while (map.val[row + square.size - 1][col] && col < square.col
		+ square.size) // Check botomn side
	{
		if (map.val[row + square.size - 1][col] != map.c_empty)
			return (0);
		col++;
	}
	return (1);
}
// Square positioned within the map and there is no obstacles
int	is_right_side_valid(struct square square, struct map map)
{
	int		row;
	char	value;

	row = square.row;
	while (map.val[row] && row < square.row + square.size)
	{
		value = map.val[row][square.col + square.size - 1];
		if (value == '\0' || value != map.c_empty)
			return (0);
		row++;
	}
	if (row < square.row + square.size)
		return (0);
	return (1);
}

// Square positioned within the map and there is no obstacles
int	is_bottom_side_valid(struct square square, struct map map)
{
	int		col;
	char	value;

	col = square.col;
	if (map.val[square.row + square.size - 1] == NULL)
		return (0);
	while (map.val[square.row + square.size - 1][col] && col < square.col
		+ square.size)
	{
		value = map.val[square.row + square.size - 1][col];
		if (value == '\0' || value != map.c_empty)
			return (0);
		col++;
	}
	return (1);
}
