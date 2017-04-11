/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_ncurses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slesik <slesik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 15:57:56 by slesik            #+#    #+#             */
/*   Updated: 2017/03/21 02:59:00 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void			ncurses_option(t_game *play)
{
	getmaxyx(stdscr, play->env.col, play->env.row);
	check_valid_win(play);
	ncurses_grid(play);
	scores(play);
	if (play->env.win)
		player_win(play);
	attron(COLOR_PAIR(2));
	edges(play);
	attroff(COLOR_PAIR(2));
}

void			ncurses_numbers(t_game *play)
{
	int		i;
	int		j;
	int		var;
	t_pos	cur;

	i = 0;
	j = 0;
	cur.x = play->env.size.x / 2;
	cur.y = play->env.size.y / 2;
	while (i < play->map.size)
	{
		var = cur.x;
		while (j < play->map.size)
		{
			case_nb_ncurses(play, cur, i, j);
			cur.x += play->env.size.x;
			j++;
		}
		cur.x = var;
		cur.y += play->env.size.y;
		j = 0;
		i++;
	}
}

void			case_nb_ncurses(t_game *play, t_pos cur, int i, int j)
{
	set_ccase(play, play->map.grid[i][j]);
	filter_case(play, cur.x - play->env.size.x / 2 + 1,
		cur.y - play->env.size.y / 2 + 1);
	attron(A_NORMAL);
	if (play->map.grid[i][j])
	{
		mvprintw(cur.y, (cur.x - ft_intlen(play->map.grid[i][j])), "%d",
			play->map.grid[i][j]);
	}
	attroff(A_NORMAL | COLOR_PAIR(play->env.color_pair));
}

void			ncurses_grid(t_game *play)
{
	attron(COLOR_PAIR(2));
	set_col_grid(play);
	set_line_grid(play);
	attroff(play->env.color_pair);
	ncurses_numbers(play);
}

void			key_hook(t_game *play)
{
	int		ch;
	t_pos	pl;

	ch = getch();
	if (ch)
	{
		if (ch == ESC)
			quit_game(play);
		if (ch == K_LEFT)
			set_position(&pl, -1, 0);
		else if (ch == K_RIGHT)
			set_position(&pl, 1, 0);
		else if (ch == K_UP)
			set_position(&pl, 0, -1);
		else if (ch == K_DOWN)
			set_position(&pl, 0, 1);
		play->env.played = 1;
		if (ch == K_LEFT || ch == K_RIGHT || ch == K_UP || ch == K_DOWN)
			move_function(play, pl);
	}
}
