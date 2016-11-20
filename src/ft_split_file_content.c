/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_file_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:46:46 by gbrochar          #+#    #+#             */
/*   Updated: 2016/01/07 18:35:50 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetromino	*ft_split_file_content(char *file_content, int tiles_nb)
{
	char	**tiles;
	int		i;
	int		i_tiles;
	int		i_file;

	i_file = 0;
	i = 0;
	tiles = (char **)malloc((tiles_nb + 1) * sizeof(char *));
	while (i != tiles_nb)
		tiles[i++] = ft_strnew(21);
	tiles[i] = NULL;
	i = -1;
	while (++i != tiles_nb)
	{
		i_tiles = 0;
		while (i_tiles != 21)
		{
			tiles[i][i_tiles++] = file_content[i_file];
			i_file++;
		}
	}
	tiles[tiles_nb - 1][20] = '\n';
	return (ft_check_tiles(tiles));
}
