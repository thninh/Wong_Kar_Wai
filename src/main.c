/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 02:23:38 by thninh            #+#    #+#             */
/*   Updated: 2017/03/21 14:21:15 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		init_grid(t_game *play, int size)
{
	int i;

	i = 0;
	play->map.size = size;
	play->map.grid = (int **)ft_memalloc(sizeof(int *) * size + 1);
	if (!play->map.grid)
		gestion_error(3);
	while (i < size)
	{
		play->map.grid[i] = (int *)ft_memalloc(sizeof(int) * size);
		if (!play->map.grid[i])
			gestion_error(3);
		i++;
	}
	play->map.grid[i] = NULL;
}

static void		options_colors(void)
{
	start_color();
	init_pair(1, 0, COLOR_WHITE);
	init_pair(2, 0, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	init_pair(4, COLOR_BLACK, 245);
	init_pair(5, COLOR_BLACK, 223);
	init_pair(6, COLOR_BLACK, 203);
	init_pair(7, COLOR_BLACK, COLOR_YELLOW);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_GREEN);
	init_pair(10, COLOR_BLACK, 93);
	init_pair(11, COLOR_BLACK, 203);
	init_pair(12, COLOR_BLACK, 53);
	init_pair(13, COLOR_BLACK, 167);
	init_pair(14, COLOR_BLACK, 54);
	init_pair(15, COLOR_BLACK, COLOR_CYAN);
	init_pair(16, COLOR_YELLOW, COLOR_RED);
	init_pair(17, COLOR_BLACK, 130);
}

static void		open_ncurses(t_game *play)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	noecho();
	srand(time(NULL));
	if (has_colors() == FALSE)
		gestion_error(1);
	getmaxyx(stdscr, play->env.col, play->env.row);
}

void			init_game(t_game *play)
{
	play->env.op = 4;
	check_value(WIN_VALUE);
	open_ncurses(play);
	options_colors();
	init_grid(play, play->env.op);
	gen_new_number(play);
	gen_new_number(play);
	play->env.played = 0;
	play->env.score = 0;
	play->env.win = 0;
}

int				main(void)
{
	t_game	play;

	init_game(&play);
	start_menu(&play);
	while (1)
	{
		ncurses_option(&play);
		key_hook(&play);
		check_game_play(&play);
		clear();
		refresh();
	}
	endwin();
	return (0);
}
