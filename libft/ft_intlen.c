/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:51:00 by slesik            #+#    #+#             */
/*   Updated: 2017/03/19 16:51:02 by slesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define ABS(x) ((x < 0) ? -(x) : (x));

int		ft_intlen(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		nb = ABS(nb);
		i++;
	}
	while (nb / 10 > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i + 1);
}
