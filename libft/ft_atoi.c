/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:29:23 by thninh            #+#    #+#             */
/*   Updated: 2017/02/16 15:01:07 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		n;

	i = 0;
	neg = 0;
	n = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	if (neg == -1)
		return (-1 * n);
	return (n);
}
