/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:54:32 by gbrochar          #+#    #+#             */
/*   Updated: 2016/02/24 20:02:56 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tetromino		*tiles;
	int				i;

	i = 0;
	if (argc == 2)
	{
		tiles = ft_get_file(argv[1]);
		if (!tiles)
			ft_putstr_fd("error\n", 2);
		else
			ft_solve(tiles);
	}
	else
		ft_putstr_fd("usage: ./fillit source_file\n", 2);
	return (0);
}
