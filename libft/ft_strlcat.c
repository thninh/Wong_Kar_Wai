/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:19:58 by thninh            #+#    #+#             */
/*   Updated: 2016/11/17 14:18:08 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s1_end;

	i = 0;
	s1_end = ft_strlen((const char *)dest);
	if (size <= s1_end)
		return (size + ft_strlen(src));
	while (src[i] && i < (size - s1_end - 1))
	{
		dest[s1_end + i] = src[i];
		i++;
	}
	dest[s1_end + i] = '\0';
	return (s1_end + ft_strlen(src));
}
