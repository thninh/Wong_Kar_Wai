/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 03:58:20 by thninh            #+#    #+#             */
/*   Updated: 2017/03/21 05:05:26 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		limit_grid(t_game *play, int y, int x)
{
	if (y >= 0 && x >= 0 && y < play->env.op && x < play->env.op)
		return (1);
	return (0);
}

static int		move_block(t_game *play, t_pos pl, t_pos pos)
{
	int i;

	i = 0;
	while (limit_grid(play, pos.y, pos.x) && limit_grid(play, pos.y + pl.y, pos.x + pl.x)
		&& GRID[pos.y + pl.y][pos.x + pl.x] == 0)
	{
		GRID[pos.y + pl.y][pos.x + pl.x] = GRID[pos.y][pos.x];
		GRID[pos.y][pos.x] = 0;
		pos.y += pl.y;
		pos.x += pl.x;
		i++;
	}
	if (limit_grid(play, pos.y, pos.x) && limit_grid(play, pos.y + pl.y, pos.x + pl.x)
		&& (GRID[pos.y + pl.y][pos.x + pl.x] > 0 &&
			GRID[pos.y + pl.y][pos.x + pl.x] == GRID[pos.y][pos.x]))
	{
		i = 1;
		GRID[pos.y + pl.y][pos.x + pl.x] = GRID[pos.y][pos.x] * 2;
		if (GRID[pos.y + pl.y][pos.x + pl.x] == WIN_VALUE)
			play->env.win = 1;
		play->env.score += GRID[pos.y + pl.y][pos.x + pl.x];
		GRID[pos.y][pos.x] = 0;
		return (i);
	}
	return (i);
}

static int		init_pmove(t_game *play, t_pos *pos, t_pos pl, int *suc)
{
	if (pl.x == 1 || pl.y == 1)
	{
		pos->x = play->env.op - 1;
		pos->y = play->env.op - 1;
		*suc = -1;
		return (1);
	}
	if (pl.x == -1 || pl.y == -1)
	{
		pos->x = 0;
		pos->y = 0;
		*suc = 1;
		return (2);
	}
	return (-1);
}

static int		check_pl(t_game *play, int mode, int pos)
{
	if (mode == 1)
	{
		if (pos >= 0)
			return (1);
	}
	if (mode == 2)
	{
		if (pos < play->env.op)
			return (1);
	}
	return (0);
}

void			move_function(t_game *play, t_pos pl)
{
	t_pos	pos;
	int		mode;
	int		v;

	mode = init_pmove(play, &pos, pl, &v);
	while (check_pl(play, mode, pos.y))
	{
		while (check_pl(play, mode, pos.x))
		{
			if (play->map.grid[pos.y][pos.x] > 0)
			{
				if (move_block(play, pl, pos))
					play->env.moved = 1;
			}
			pos.x += v;
		}
		pos.y += v;
		if (mode == 1)
			pos.x = play->env.op - 1;
		else
			pos.x = 0;
	}
}
