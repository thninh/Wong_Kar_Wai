/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:20:30 by thninh            #+#    #+#             */
/*   Updated: 2016/11/17 13:40:13 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s1 && !*s2)
		return ((char*)s1);
	if (n < ft_strlen(s2))
		return (NULL);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] && s2[j] && i + j < n)
			j++;
		if (!s2[j] || j == n)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
