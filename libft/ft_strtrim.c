/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:47:59 by thninh            #+#    #+#             */
/*   Updated: 2016/11/13 17:49:49 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		trim_len(char *s)
{
	size_t			space;
	size_t			i;
	size_t			len_s;

	i = 0;
	len_s = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	space = i;
	if (s[i] != '\0')
	{
		i = len_s - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i--;
			space++;
		}
	}
	return (len_s - space);
}

char				*ft_strtrim(char const *s)
{
	char			*result;
	size_t			len;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	len = 0;
	result = NULL;
	if (s)
	{
		len = trim_len((char *)s);
		result = (char *)malloc(sizeof(*result) * len + 1);
	}
	if (!(s && result))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < len)
		result[j++] = s[i++];
	result[j] = '\0';
	return (result);
}
