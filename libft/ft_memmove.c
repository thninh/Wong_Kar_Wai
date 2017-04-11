/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:22:51 by thninh            #+#    #+#             */
/*   Updated: 2016/11/13 13:50:48 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n == 0)
		return (dest);
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	n--;
	while (n > 0)
	{
		((unsigned char*)dest)[n] = ((unsigned char*)src)[n];
		n--;
	}
	((unsigned char*)dest)[n] = ((unsigned char*)src)[n];
	return (dest);
}
