/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:45:50 by thninh            #+#    #+#             */
/*   Updated: 2016/11/13 17:23:25 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		lengths(int n)
{
	int			len;
	long int	l;

	len = 0;
	l = n;
	if (l < 0)
	{
		len++;
		l = -n;
	}
	while (l != l % 10)
	{
		len++;
		l = (l - l % 10) / 10;
	}
	len++;
	return (len);
}

char			*ft_itoa(int n)
{
	int			len;
	int			cur;
	char		*str;
	long int	ln;

	ln = n;
	len = lengths(n);
	str = (char *)malloc(sizeof(*str) * len + 1);
	if (!str)
		return (NULL);
	cur = 0;
	if (n < 0)
	{
		str[cur] = '-';
		ln *= -1;
	}
	while (cur < ((n < 0) ? len - 1 : len))
	{
		str[len - cur - 1] = (ln % 10) + 48;
		ln = (ln - ln % 10) / 10;
		cur++;
	}
	str[len] = '\0';
	return (str);
}
