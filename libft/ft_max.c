/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:11:44 by thninh            #+#    #+#             */
/*   Updated: 2016/11/17 15:16:00 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				max;

	i = 0;
	if (len <= 0)
		return (0);
	while (tab[i])
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}
