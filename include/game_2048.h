/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 01:51:35 by thninh            #+#    #+#             */
/*   Updated: 2017/03/21 04:24:54 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <form.h>
# include <stdio.h>
# include <stdlib.h>
# include <ncurses.h>
# include <string.h>
# include <time.h>
# include "../libft/libft.h"

# define MAP_SIZE 4
# define GRID play->map.grid
# define Y play->env.col
# define X play->env.row

enum	e_const
{
	WIN_VALUE = 2048
};

typedef enum	e_keys
{
	ESC = 27,
	K_RIGHT = 261,
	K_LEFT = 260,
	K_UP = 259,
	K_DOWN = 258,
	K_ONE = 49,
	K_TWO = 50,
	OP = 51,
}				t_keys;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_env
{
	int			row;
	int			col;
	t_pos		size;
	int			color_pair;
	int			played;
	int			moved;
	int			op;
	size_t		score;
	int			win;
}				t_env;

typedef struct	s_map
{
	int			**grid;
	int			size;
}				t_map;

typedef struct	s_game
{
	t_env		env;
	t_map		map;
}				t_game;

void			you_win(t_game *play);
void			gestion_error(int op);
void			check_valid_win(t_game *play);
void			edges(t_game *play);
void			quit_game(t_game *game);
void			gen_new_number(t_game *play);
void			start_menu(t_game *play);
void			init_game(t_game *play);
void			check_game_play(t_game *play);
void			filter_case(t_game *play, int x, int y);
int				set_ccase(t_game *play, int nb);
void			case_nb_ncurses(t_game *play, t_pos cur, int i, int j);
void			ncurses_grid(t_game *play);
void			display_loose(t_game *play);
void			key_hook(t_game *play);
void			check_value(int value);
void			ncurses_option(t_game *play);
void			move_function(t_game *play, t_pos pl);
void			ncurses_numbers(t_game *play);
void			set_col_grid(t_game *play);
void			set_line_grid(t_game *play);
void			set_position(t_pos *pl, int x, int y);
void			player_win(t_game *play);
void			scores(t_game *play);
void			fd_score(char *player, char *score);
int				main(void);

#endif
