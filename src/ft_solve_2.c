/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <gbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 03:36:57 by gbrochar          #+#    #+#             */
/*   Updated: 2016/02/25 08:55:13 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_del_tile(char grid[22][23], int nb)
{
	int		i;
	int		j;

	i = 0;
	while (i != grid[21][22])
	{
		j = 0;
		while (j != grid[21][22])
		{
			if (grid[i][j] == nb)
				grid[i][j] = -1;
			++j;
		}
		++i;
	}
}

int		ft_update_position(t_tetromino *tiles, int nb, char grid[22][23])
{
	if (tiles[nb].y == (grid[21][22] - 1) && tiles[nb].x == (grid[21][22] - 1))
	{
		tiles[nb].y = 0;
		tiles[nb].x = 0;
		if (nb == 0)
			return (1);
		ft_del_tile(grid, nb - 1);
		return (ft_update_position(tiles, nb - 1, grid) + 2);
	}
	else if (tiles[nb].y == (grid[21][22] - 1))
	{
		++tiles[nb].x;
		tiles[nb].y = 0;
	}
	else
		++tiles[nb].y;
	return (0);
}

int		ft_solve_2(char grid[22][23], t_tetromino *tiles, int nb)
{
	int		ret;
	int		(*f_check[19])(char[22][23], t_tetromino *tiles, int nb);

	init(f_check);
	if (tiles[nb].type == -1)
		return (0);
	while ((f_check[(int)(tiles[nb].type)](grid, tiles, nb)) == 1)
	{
		if ((ret = ft_update_position(tiles, nb, grid)) == 1)
			++grid[21][22];
		else
			while (ret != 0)
			{
				return (2);
			}
	}
	return (1);
}
