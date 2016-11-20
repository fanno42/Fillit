/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ir0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <gbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 05:01:23 by gbrochar          #+#    #+#             */
/*   Updated: 2016/02/17 15:23:55 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_ir0(char grid[22][23], t_tetromino *tiles, int nb)
{
	int			x;
	int			y;

	x = tiles[nb].x;
	y = tiles[nb].y;
	if (x + 3 >= grid[21][22])
		return (1);
	if (grid[x][y] == -1 && grid[x + 1][y] == -1
		&& grid[x + 2][y] == -1 && grid[x + 3][y] == -1)
	{
		grid[x][y] = nb;
		grid[x + 1][y] = nb;
		grid[x + 2][y] = nb;
		grid[x + 3][y] = nb;
		return (0);
	}
	return (1);
}
