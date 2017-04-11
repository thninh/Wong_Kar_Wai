/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:52:14 by thninh            #+#    #+#             */
/*   Updated: 2016/11/17 10:47:35 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	n;
	char			*new;

	n = 0;
	new = NULL;
	if (s)
		new = (char *)malloc(sizeof(*new) * ft_strlen(s) + 1);
	if (new && s && f)
	{
		while (s[n])
		{
			new[n] = f(n, (char)(s[n]));
			n++;
		}
		new[n] = '\0';
	}
	return (new);
}
