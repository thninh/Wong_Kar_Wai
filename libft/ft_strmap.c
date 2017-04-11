/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:38:37 by thninh            #+#    #+#             */
/*   Updated: 2016/11/17 10:47:18 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	i;

	i = 0;
	new = NULL;
	if (s)
		new = (char *)malloc(sizeof(*new) * ft_strlen(s) + 1);
	if (new && s && f)
	{
		while (s[i] != '\0')
		{
			new[i] = f((char)(s[i]));
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
