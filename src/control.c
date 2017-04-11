/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 02:31:27 by thninh            #+#    #+#             */
/*   Updated: 2017/03/21 10:42:15 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void			check_value(int value)
{
	while ((value % 2 == 0) && value > 1)
		value /= 2;
	if (value == 1)
		return ;
	else
	{
		ft_putstr_fd("Bad Win Value : ", 2);
		ft_putendl_fd(ft_itoa(WIN_VALUE), 2);
		exit(1);
	}
}

void			check_valid_win(t_game *play)
{
	int			large;
	int			haute;

	large = play->env.op * play->env.op + 1;
	haute = (play->env.op * (play->env.op + 1)) + 1;
	if (play->env.col < large || play->env.row < haute)
	{
		while (play->env.col < large || play->env.row < haute)
		{
			clear();
			getmaxyx(stdscr, play->env.col, play->env.row);
			mvprintw(play->env.col / 2, play->env.row / 2,
				"win size incorrect");
			mvprintw(play->env.col - 3, play->env.row / 2,
				"x = %d, y = %d", play->env.row, play->env.col);
			refresh();
			sleep(1);
		}
	}
}

void			gestion_error(int op)
{
	endwin();
	if (op == 1)
		ft_putstr("Your terminal does not support colors.\n");
	if (op == 2)
		ft_putstr("Permission denied or no file found\n");
	if (op == 3)
		ft_putstr("Your malloc does not work\n");
	exit(0);
}

static void		free_map(t_map *map)
{
	int i;

	i = 0;
	while (map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void			quit_game(t_game *game)
{
	free_map(&game->map);
	endwin();
	exit(0);
}
