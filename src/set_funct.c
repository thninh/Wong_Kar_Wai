/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slesik <slesik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:03:06 by slesik            #+#    #+#             */
/*   Updated: 2017/03/21 14:08:53 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		set_ccase(t_game *play, int nb)
{
	if (nb == 2)
		play->env.color_pair = 4;
	else if (nb == 4)
		play->env.color_pair = 5;
	else if (nb == 8)
		play->env.color_pair = 6;
	else if (nb == 16)
		play->env.color_pair = 17;
	else if (nb == 32)
		play->env.color_pair = 8;
	else if (nb == 64)
		play->env.color_pair = 9;
	else if (nb == 128)
		play->env.color_pair = 10;
	else if (nb == 256)
		play->env.color_pair = 11;
	else if (nb == 512)
		play->env.color_pair = 12;
	else if (nb == 1024)
		play->env.color_pair = 13;
	else if (nb == 2048)
		play->env.color_pair = 14;
	else
		play->env.color_pair = 3;
	return (0);
}

void	set_col_grid(t_game *play)
{
	int size_grid;
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	size_grid = play->env.row / play->env.op;
	x = size_grid;
	while (i < play->env.op - 1)
	{
		while (y < (play->env.col / play->env.op) * (play->env.op - 1))
		{
			mvprintw(y, x, "|");
			y++;
		}
		x += size_grid;
		y = 0;
		i++;
	}
	play->env.size.x = size_grid;
}

void	set_line_grid(t_game *play)
{
	int				sizeg;
	int				x;
	int				y;
	int				i;

	i = 0;
	y = 0;
	sizeg = play->env.col / (play->env.op + 1);
	x = sizeg;
	while (i < play->env.op)
	{
		while (y < play->env.row)
		{
			mvprintw(x, y, "-");
			y++;
		}
		x += sizeg;
		y = 0;
		i++;
	}
	play->env.size.y = sizeg;
}

void	set_position(t_pos *pl, int x, int y)
{
	pl->x = x;
	pl->y = y;
}
