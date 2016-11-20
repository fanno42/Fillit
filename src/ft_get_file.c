/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 07:44:27 by gbrochar          #+#    #+#             */
/*   Updated: 2016/01/09 16:17:47 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_exit(int fd, char *str)
{
	close(fd);
	free(str);
	str = NULL;
}

t_tetromino	*ft_get_file(char *file_name)
{
	int		file_des;
	int		file_len;
	char	*file_content;

	file_content = ft_strnew(546);
	file_des = open(file_name, O_RDONLY);
	if (file_des == -1)
	{
		ft_exit(file_des, file_content);
		return (NULL);
	}
	file_len = read(file_des, file_content, 546);
	if (file_len % 21 != 20)
	{
		ft_exit(file_des, file_content);
		return (NULL);
	}
	close(file_des);
	return (ft_split_file_content(file_content, ((file_len / 21) + 1)));
}
