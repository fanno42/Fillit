/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 18:32:49 by gbrochar          #+#    #+#             */
/*   Updated: 2016/02/25 11:35:48 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_allocate_types(void)
{
	char			**types;
	int				i;

	i = 0;
	types = (char **)malloc(20 * sizeof(char *));
	while (i != 20)
		types[i++] = ft_strnew(20);
	return (types);
}

char		**ft_create_types(void)
{
	char			**types;

	types = ft_allocate_types();
	types[0] = "#....#....#....#";
	types[1] = "####";
	types[2] = "##...##";
	types[3] = "###...#";
	types[4] = "#...##....#";
	types[5] = "#...###";
	types[6] = "#....##...#";
	types[7] = "##..##";
	types[8] = "#....##....#";
	types[9] = "##....##";
	types[10] = "#...##...#";
	types[11] = "#....#....##";
	types[12] = "###..#";
	types[13] = "##....#....#";
	types[14] = "#..###";
	types[15] = "#....#...##";
	types[16] = "#....###";
	types[17] = "##...#....#";
	types[18] = "###....#";
	types[19] = NULL;
	return (types);
}

t_tetromino	*ft_create_tiles(void)
{
	t_tetromino		*tiles;
	int				i;

	i = 0;
	tiles = (t_tetromino *)malloc(26 * sizeof(t_tetromino));
	while (i != 26)
	{
		tiles[i].type = -1;
		tiles[i].x = 0;
		tiles[i++].y = 0;
	}
	return (tiles);
}

void		ft_replace_linefeed(char **tiles)
{
	int				i;
	int				i2;

	i = 0;
	while (tiles[i])
	{
		i2 = 0;
		while (tiles[i][i2])
		{
			if (tiles[i][i2] == '\n' && i2 != 20)
				tiles[i][i2] = '.';
			i2++;
		}
		i++;
	}
}

t_tetromino	*ft_get_struct(char **tiles)
{
	char			**types;
	t_tetromino		*t_tiles;
	int				i;
	int				i_types;

	ft_replace_linefeed(tiles);
	types = ft_create_types();
	t_tiles = ft_create_tiles();
	i = 0;
	while (tiles[i])
	{
		i_types = 0;
		while (types[i_types])
			if (ft_strstr_binary(tiles[i], types[i_types++]) == 1)
			{
				t_tiles[i].type = i_types - 1;
				break ;
			}
		if (t_tiles[i].type == -1)
			return (NULL);
		i++;
	}
	return (t_tiles);
}
