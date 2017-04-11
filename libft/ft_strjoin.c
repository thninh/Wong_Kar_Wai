/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:38:27 by thninh            #+#    #+#             */
/*   Updated: 2016/11/17 10:46:02 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	result = NULL;
	if (s1 && s2)
		result = (char *)malloc(sizeof(*result) * (ft_strlen(s1) +
					ft_strlen(s2)) + 1);
	if (result)
		ft_strcat(ft_strcpy(result, s1), s2);
	return (result);
}
