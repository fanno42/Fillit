/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:51:35 by gbrochar          #+#    #+#             */
/*   Updated: 2016/01/08 18:35:24 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetromino	*ft_check_tiles(char **tiles)
{
	int		i;
	int		i2;
	int		hashtag_count;
	int		dot_count;

	i = -1;
	while (tiles[++i])
	{
		if (tiles[i][4] != '\n' || tiles[i][9] != '\n' || tiles[i][14] != '\n'
			|| tiles[i][19] != '\n' || tiles[i][20] != '\n')
			return (NULL);
		dot_count = 0;
		hashtag_count = 0;
		i2 = 0;
		while (i2 != 21)
		{
			if (tiles[i][i2] == '#')
				hashtag_count++;
			if (tiles[i][i2++] == '.')
				dot_count++;
		}
		if (hashtag_count != 4 || dot_count != 12)
			return (NULL);
	}
	return (ft_get_struct(tiles));
}
