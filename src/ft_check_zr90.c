/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_zr90.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <gbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 05:01:23 by gbrochar          #+#    #+#             */
/*   Updated: 2016/02/17 15:25:04 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_zr90(char grid[22][23], t_tetromino *tiles, int nb)
{
	int			x;
	int			y;

	x = tiles[nb].x;
	y = tiles[nb].y;
	if (x + 2 >= grid[21][22] || y + 1 >= grid[21][22])
		return (1);
	if (grid[x][y + 1] == -1 && grid[x + 1][y] == -1
		&& grid[x + 1][y + 1] == -1 && grid[x + 2][y] == -1)
	{
		grid[x][y + 1] = nb;
		grid[x + 1][y] = nb;
		grid[x + 1][y + 1] = nb;
		grid[x + 2][y] = nb;
		return (0);
	}
	return (1);
}
