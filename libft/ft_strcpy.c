/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:04:21 by thninh            #+#    #+#             */
/*   Updated: 2016/11/11 14:01:06 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dest, const char *src)
{
	int		i;
	char	*test;

	i = 0;
	test = (char *)src;
	while (test[i] != '\0')
	{
		dest[i] = test[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
