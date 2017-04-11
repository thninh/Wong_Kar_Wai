/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 03:09:42 by thninh            #+#    #+#             */
/*   Updated: 2017/03/21 09:42:24 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void			logo(t_game *play)
{
	int			l;
	int			c;

	l = 2;
	c = play->env.row / 2 - 19;
	attron(COLOR_PAIR(8));
	mvprintw(l, c, "                                    ");
	mvprintw(++l, c, "     ###    ####   #         ####   ");
	mvprintw(++l, c, "    #   #  #    #  #    #   #    #  ");
	mvprintw(++l, c, "        #  #    #  #    #   #    #  ");
	mvprintw(++l, c, "      ##   #    #  #######   ####   ");
	mvprintw(++l, c, "    ##     #    #       #   #    #  ");
	mvprintw(++l, c, "    #      #    #       #   #    #  ");
	mvprintw(++l, c, "    #####   ####        #    ####   ");
	mvprintw(++l, c, "                                    ");
	attron(COLOR_PAIR(7));
	mvprintw(l + 2, c - 4, "Join the numbers and get to the 2048 tile!");
	refresh();
}

void				edges(t_game *play)
{
	int	i;
	int	j;

	attron(COLOR_PAIR(8));
	i = 0;
	while (i < play->env.row)
	{
		mvprintw(0, i, " ");
		mvprintw(play->env.col - 1, i, " ");
		i++;
	}
	j = 0;
	while (j < play->env.col)
	{
		mvprintw(j, 0, " ");
		mvprintw(j, play->env.row - 1, " ");
		j++;
	}
}

static void			menu_game(t_game *play)
{
	logo(play);
	edges(play);
	attron(COLOR_PAIR(8));
	mvprintw(play->env.col / 2 - 5,
		play->env.row / 2 - ft_strlen(" 1 - Play "), " 1 - Play ");
	mvprintw(play->env.col / 2 - 3,
		play->env.row / 2 - ft_strlen(" 2 - Quit "), " 2 - Quit ");
	mvprintw(play->env.col / 2 - 1,
		play->env.row / 2 - ft_strlen(" 3 - Option ") + 1, " 3 - Option ");
	refresh();
}

void 		menu_option(t_game *play)
{
	int						ch;

	ch = 0;
	while (1)
	{
		clear();
		edges(play);
		attron(COLOR_PAIR(8));
		mvprintw(play->env.col / 2 - 10, play->env.row / 2 - 15,
		"                                 ");
		mvprintw(play->env.col / 2 - 9, play->env.row / 2 - 15,
		" choose the size of the game !!! ");
		mvprintw(play->env.col / 2 - 8, play->env.row / 2 - 15,
		"                                 ");
		mvprintw(play->env.col / 2, play->env.row / 2 - 5,
		" 1 - 4 x 4 ");
		mvprintw(play->env.col / 2 + 2, play->env.row / 2 - 5,
		" 2 - 5 x 5 ");
		refresh();
		ch = getch();
		if (ch == ESC || ch == K_ONE)
		{
				play->env.op = 4;
				break;
		}
		if (ch == K_TWO)
		{
			play->env.op = 5;
			break;
		}
	}
}

void				start_menu(t_game *play)
{
	int			ch;

	ch = 0;
	while (ch != 49)
	{
		menu_game(play);
		ch = getch();
		if (ch == 27 || ch == 50)
			quit_game(play);
		else if (ch == OP)
			menu_option(play);
	//	else
		//	play->env.op = 4;
		clear();
		refresh();
	}
}
