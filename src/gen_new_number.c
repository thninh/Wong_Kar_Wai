/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_new_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slesik <slesik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:14:36 by slesik            #+#    #+#             */
/*   Updated: 2017/03/21 09:31:08 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		gen_new_number(t_game *play)
{
	int		i;
	int		nb;
	t_pos	pos;

	i = 0;
	pos.x = 0;
	pos.y = 0;
	nb = ft_rand_a_b(1, 3);
	while (i == 0 || play->map.grid[pos.y][pos.x] != 0)
	{
		pos.y = ft_rand_a_b(0, MAP_SIZE);
		pos.x = ft_rand_a_b(0, MAP_SIZE);
		i++;
	}
	play->map.grid[pos.y][pos.x] = nb * 2;
	play->env.moved = 0;
}

void		scores(t_game *play)
{
	attron(COLOR_PAIR(15));
	mvprintw(play->env.col - 10, play->env.row / 2 - 9, "  Score %d  ",
			play->env.score);
}
