/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:24:55 by thninh            #+#    #+#             */
/*   Updated: 2016/11/12 13:51:59 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*memo;

	memo = (void *)malloc(sizeof(*memo) * size);
	if (memo)
	{
		ft_memset(memo, 0, size);
		return (memo);
	}
	return (NULL);
}
