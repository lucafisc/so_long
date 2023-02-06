/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:19 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/06 16:28:27 by lde-ross         ###   ########.fr       */
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
# define RIGHT 65361
# define C_RIGHT 100



typedef enum s_bool
{
	false,
	true
}	t_bool;

/* vector with an x and y */
typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

/* A pointer to the window and its size */
typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;

/* The 4 values that define a color */
typedef struct s_color {
	int	r;
	int g;
	int b;
	int a;
}	t_color;

typedef struct s_player
{
	void	*current_img;
	int		framecount;
	int		idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	int		action_frames;
}	t_player;


/* all info needed for an image */
typedef struct	s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_map
{
	t_vector	size;
}	t_map;

typedef struct	s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
	t_vector	img_size;
	t_player	player;
	t_map		map;
}				t_program;

void		ft_putnbr(int n);
void		ft_putchar(char c);
void		hooks(t_program *app);
t_window	new_window(void *mlx, int widht, int height, char *name);
void		draw_square(t_program *app, int x, int y, int width, int height, int color);
t_bool	is_map_valid(char *str, t_map *map);
int		main(int argc, char *argv[]);




#endif