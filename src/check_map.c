/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 04:41:13 by thninh            #+#    #+#             */
/*   Updated: 2017/03/21 04:54:09 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		second_check(t_game *play, int *k)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < play->env.op)
	{
		while (i < play->env.op - 1)
		{
			if (play->map.grid[i][j] != play->map.grid[i + 1][j])
				*k += 1;
			i++;
		}
		i = 0;
		j++;
	}
	return (*k);
}

int				fonct_iterative(int taille)
{
	int	n;
	int	result;

	n = 1;
	result = 1;
	while (n <= taille)
	{
		result = result * n;
		n++;
	}
	return (result);
}

static int		first_check(t_game *play)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < play->env.op)
	{
		while (j < play->env.op - 1)
		{
			if (play->map.grid[i][j] != play->map.grid[i][j + 1])
				k++;
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	second_check(play, &k);
	return (k == fonct_iterative(play->env.op)) ? 1 : 0;
}

static int		check_valid_tab(t_game *play)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (play->map.grid[i])
	{
		while (j < play->env.op)
		{
			if (play->map.grid[i][j] == 0)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void			check_game_play(t_game *play)
{
	if (play->env.played)
	{
		if (check_valid_tab(play) == 0)
		{
			if (first_check(play) == 1)
				display_loose(play);
		}
		else if (play->env.moved)
			gen_new_number(play);
		play->env.played = 0;
	}
}
