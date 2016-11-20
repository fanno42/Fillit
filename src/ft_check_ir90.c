/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ir90.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <gbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 05:01:23 by gbrochar          #+#    #+#             */
/*   Updated: 2016/02/17 15:24:01 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_ir90(char grid[22][23], t_tetromino *tiles, int nb)
{
	int			x;
	int			y;

	x = tiles[nb].x;
	y = tiles[nb].y;
	if (y + 3 >= grid[21][22])
		return (1);
	if (grid[x][y] == -1 && grid[x][y + 1] == -1
		&& grid[x][y + 2] == -1 && grid[x][y + 3] == -1)
	{
		grid[x][y] = nb;
		grid[x][y + 1] = nb;
		grid[x][y + 2] = nb;
		grid[x][y + 3] = nb;
		return (0);
	}
	return (1);
}
