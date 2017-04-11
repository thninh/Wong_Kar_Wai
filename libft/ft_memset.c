/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:07:05 by thninh            #+#    #+#             */
/*   Updated: 2016/11/11 14:45:24 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*cur;

	cur = (unsigned char *)str;
	while (n)
	{
		*cur = (unsigned char)c;
		cur++;
		n--;
	}
	return (str);
}
