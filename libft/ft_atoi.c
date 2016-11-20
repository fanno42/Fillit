/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:18:43 by gbrochar          #+#    #+#             */
/*   Updated: 2016/02/10 17:16:28 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	result;
	long	sign;
	char	*str2;

	str2 = (char *)str;
	result = 0;
	while (ft_isspace(*str2))
		str2++;
	sign = (*str2 == '-') ? -1 : 1;
	if (*str2 == '-' || *str2 == '+')
		str2++;
	while (*str2 >= '0' && *str2 <= '9')
	{
		result = (result * 10) + (*str2 - '0');
		str2++;
	}
	return ((int)(result * sign));
}
