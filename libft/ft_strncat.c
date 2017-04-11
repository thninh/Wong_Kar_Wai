/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:20:06 by thninh            #+#    #+#             */
/*   Updated: 2016/11/17 10:47:54 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen((const char *)dest);
	if (n == 0)
		return (dest);
	while (i < n && src[i] != '\0')
	{
		dest[len + i] = ((char*)src)[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
