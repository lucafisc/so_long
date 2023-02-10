/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:19 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/10 17:14:03 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "mlx.h"

# define UP 65362
# define C_UP 119
# define DOWN 65364
# define C_DOWN 115
# define LEFT 65361
# define C_LEFT 97
# define RIGHT 65363
# define C_RIGHT 100

typedef enum s_bool
{
	false,
	true
}	t_bool;

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct	s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_player
{
	void		*current_img;
	void		*player_img_1;
	void		*player_img_2;
	int			counter;
	int			total_frames;
	t_vector	position;
}	t_player;

typedef struct s_egg
{
	void	*current_img;
	void	*egg_img_1;
	void	*egg_img_2;
	void	*egg_img_3;
	int		counter;
	int		total_frames;
}	t_egg;

typedef struct s_heart
{
	void	*current_img;
	void	*heart_img_1;
	void	*heart_img_2;
	void	*heart_img_3;
	int		counter;
	int		total_frames;
}	t_heart;

typedef struct s_wall
{
	void	*wall_img_1;
	void	*wall_img_2;
	void	*frame_img;
}	t_wall;

typedef struct s_map
{
	t_vector	size;
	t_bool		allocated;
	char		**matrix;
}	t_map;

typedef struct s_exit
{
	void	*exit_closed_img;
	void	*exit_open_img;
	t_vector	exit_vector;
} t_exit;

typedef struct s_enemy
{
	void		*current_img;
	void		*enemy_img_1;
	void		*enemy_img_2;
	int			counter;
	int			total_frames;
	t_vector	position;
}	t_enemy;

typedef struct	s_program {
	void		*mlx;
	t_window	window;
	int			img_size;
	t_map		map;
	t_player	player;
	t_egg		egg;
	t_wall		wall;
	t_exit		exit;
	t_heart		heart;
	int			moves;
	t_bool		finish;
	t_bool		collected;
	t_enemy		enemy;
}				t_program;

void		ft_putnbr(int n);
void		ft_putchar(char c);
void		hooks(t_program *app);
t_window	new_window(void *mlx, int widht, int height, char *name);
void		draw_square(t_program *app, int x, int y, int width, int height, int color);
t_bool		map_is_valid(char *str, t_map *map);
int			main(int argc, char *argv[]);
int			control(int key, void *param);
int			close_app(void *param);


//init
void	init_game(t_program *app);

//errors
void		invalid_map(t_map *map);
void		invalid_args(char *str);

//map
t_vector	get_map_size(char *str);
void		free_map(t_map *map);
void		get_map(char *str, t_map *map);

//animation
void	player_animation(t_program *app);
void	egg_animation(t_egg *egg);
void	heart_animation(t_heart *heart);
void	enemy_animation(t_program *app);


void	open_exit(t_program *app);
t_bool	all_eggs_collected(t_program *app);

int random_number(void);

#endif