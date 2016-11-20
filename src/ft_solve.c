/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:37:23 by gbrochar          #+#    #+#             */
/*   Updated: 2016/02/24 15:42:56 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init(int (*f_check[19])(char[22][23], t_tetromino *, int))
{
	f_check[0] = &ft_check_ir0;
	f_check[1] = &ft_check_ir90;
	f_check[2] = &ft_check_or0;
	f_check[3] = &ft_check_tr0;
	f_check[4] = &ft_check_tr90;
	f_check[5] = &ft_check_tr180;
	f_check[6] = &ft_check_tr270;
	f_check[7] = &ft_check_sr0;
	f_check[8] = &ft_check_sr90;
	f_check[9] = &ft_check_zr0;
	f_check[10] = &ft_check_zr90;
	f_check[11] = &ft_check_lr0;
	f_check[12] = &ft_check_lr90;
	f_check[13] = &ft_check_lr180;
	f_check[14] = &ft_check_lr270;
	f_check[15] = &ft_check_jr0;
	f_check[16] = &ft_check_jr90;
	f_check[17] = &ft_check_jr180;
	f_check[18] = &ft_check_jr270;
}

void	ft_init_grid(char grid[22][23], t_tetromino *tiles)
{
	int		i;
	int		j;

	i = 0;
	while (i != 22)
	{
		j = 0;
		while (j != 22)
			grid[i][j++] = -1;
		i++;
	}
	j = 2;
	i = 0;
	while (tiles[i].type != -1 && i != 26)
		++i;
	i *= 4;
	while (j * j < i)
		++j;
	grid[21][22] = j;
}

void	ft_solve(t_tetromino *tiles)
{
	char	grid[22][23];
	int		nb;
	int		ret;

	nb = 0;
	ft_init_grid(grid, tiles);
	while ((ret = ft_solve_2(grid, tiles, nb)) != 0)
	{
		if (ret == 1)
			++nb;
		else
			--nb;
	}
	ft_print_grid(grid);
}
