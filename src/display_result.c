/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slesik <slesik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:07:20 by slesik            #+#    #+#             */
/*   Updated: 2017/03/21 04:52:59 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		filter_case(t_game *play, int x, int y)
{
	int i;
	int j;

	i = 0;
	attron(COLOR_PAIR(play->env.color_pair));
	while (i < play->env.size.y - 1)
	{
		j = 0;
		while (j < play->env.size.x - 1)
		{
			mvprintw(y, x, " ");
			x++;
			j++;
		}
		x -= j;
		y++;
		i++;
	}
}

void		you_win(t_game *play)
{
	attron(COLOR_PAIR(16));
	mvprintw(Y - 8, X / 2 - 40, "                                        ");
	mvprintw(Y - 8, X / 2, "                                       ");
	mvprintw(Y - 7, X / 2 - 40, "     xxx   xxx  xxx   xxx  xxx   xxxx   ");
	mvprintw(Y - 7, X / 2, " xxxx    xxxx   xxxx   xxxxx  xxxx     ");
	mvprintw(Y - 6, X / 2 - 40, "      xx   xx  x   x  xxx  xxx    xxx   ");
	mvprintw(Y - 6, X / 2, " xxxx    xxx     xx     xxxx   xx      ");
	mvprintw(Y - 5, X / 2 - 40, "        xxx   xx   xx xxx  xxx     xx   ");
	mvprintw(Y - 5, X / 2, "xx  xx   xx      xx     xx xx  xx      ");
	mvprintw(Y - 4, X / 2 - 40, "        xxx    x   x   xx  xx       xx x");
	mvprintw(Y - 4, X / 2, "x    xx xx       xx     xx   xxxx      ");
	mvprintw(Y - 3, X / 2 - 40, "        xxx     xxx     xxxx        xxxx");
	mvprintw(Y - 3, X / 2, "x    xxxxx      xxxx   xxxx  xxxxx     ");
	mvprintw(Y - 2, X / 2 - 40, "                                        ");
	mvprintw(Y - 2, X / 2, "                                       ");
}

void		player_win(t_game *play)
{
	t_pos		count;
	t_pos		coord;
	float		x;
	float		y;

	count.y = 0;
	count.x = 1;
	you_win(play);
	while (count.y++ < 8)
		init_pair(count.y + 1, COLOR_WHITE, count.y);
	x = (float)play->env.row;
	y = (float)play->env.col;
	while (count.x++ < 100000)
	{
		(getch() == 27) ? quit_game(play) : 0;
		count.y = 1 + (int)(8.0 * rand() / (RAND_MAX + 1.0));
		attron(COLOR_PAIR(count.y));
		coord.x = (int)((x) * rand() / (RAND_MAX + 1.0));
		coord.y = (int)((y - (y / (play->env.op + 1))) * rand() / (RAND_MAX + 1.0));
		mvprintw(coord.y, coord.x, " ");
		attroff(COLOR_PAIR(count.y));
		refresh();
	}
	endwin();
}

void		fd_score(char *player, char *score)
{
	int		fd;

	fd = open("scores.txt", O_RDWR | O_APPEND | O_CREAT, S_IRWXU);
	if (fd == -1)
	{
		ft_putstr("No file found\n");
		gestion_error(2);
	}
	ft_putstr_fd(player, fd);
	ft_putstr_fd(" = ", fd);
	ft_putstr_fd(score, fd);
	ft_putstr_fd(" pts \n", fd);
}

void		display_loose(t_game *play)
{
	int		ch;
	char	*player;

	ch = 0;
	player = NULL;
	attron(COLOR_PAIR(8));
	mvprintw(play->env.col - 3, play->env.row / 2 - 17,
		"You Loose ! Press ESC to quit");
	while (getch() != ESC)
		;
	endwin();
	ft_putstr("Enter your name : ");
	get_next_line(1, &player);
	if (player)
		fd_score(player, ft_itoa(play->env.score));
	quit_game(play);
}
