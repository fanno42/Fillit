/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_lr270.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <gbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:36:00 by gbrochar          #+#    #+#             */
/*   Updated: 2016/02/17 15:31:26 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_lr270(char grid[22][23], t_tetromino *tiles, int nb)
{
	int			x;
	int			y;

	x = tiles[nb].x;
	y = tiles[nb].y;
	if (x + 1 >= grid[21][22] || y + 2 >= grid[21][22])
		return (1);
	if (grid[x][y + 2] == -1 && grid[x + 1][y] == -1
		&& grid[x + 1][y + 1] == -1 && grid[x + 1][y + 2] == -1)
	{
		grid[x][y + 2] = nb;
		grid[x + 1][y] = nb;
		grid[x + 1][y + 1] = nb;
		grid[x + 1][y + 2] = nb;
		return (0);
	}
	return (1);
}
