/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:24:53 by gbrochar          #+#    #+#             */
/*   Updated: 2016/01/09 11:40:50 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_strstr_binary(const char *s1, char *s2)
{
	int		i;
	int		i_mem;
	int		i_tofind;

	i_mem = 0;
	while (s1[i_mem] != '\0')
	{
		i_tofind = 0;
		while (s1[i_mem] != s2[i_tofind] && s1[i_mem] != '\0')
			i_mem++;
		if (s1[i_mem] == '\0')
			return (0);
		i = i_mem;
		while (s1[i++] == s2[i_tofind] || s2[i_tofind] == '\0')
			if (s2[i_tofind++] == '\0')
				return (1);
		i_mem++;
	}
	return (0);
}
