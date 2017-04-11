/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:37:07 by thninh            #+#    #+#             */
/*   Updated: 2016/11/17 10:44:09 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dest, const char *src)
{
	char	*cop;
	size_t	len;
	size_t	i;

	i = 0;
	cop = (char *)src;
	len = ft_strlen((const char *)dest);
	if (*cop)
	{
		while (cop[i] != '\0')
		{
			dest[len + i] = cop[i];
			i++;
		}
		dest[len + i] = '\0';
	}
	return (dest);
}
