/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <gbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 05:18:57 by gbrochar          #+#    #+#             */
/*   Updated: 2016/02/15 05:29:30 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_grid(char grid[22][23])
{
	int		i;
	int		j;

	i = 0;
	while (i != grid[21][22])
	{
		j = 0;
		while (j != grid[21][22])
		{
			if (grid[i][j] == -1)
				ft_putchar('.');
			else
				ft_putchar(grid[i][j] + 'A');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
