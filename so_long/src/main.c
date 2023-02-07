/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:55:04 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/07 17:54:43 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

typedef	struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

// int mouse_event(int button, int x, int y, void *param)
// {
// 	printf("%d %d %d\n", button, x, y);
// 	draw_square(mlx, win, 640 / 2, 360 / 2, 200, 100, 0xFFFFFF);
//     // ft_putnbr(button);
// 	// ft_putnbr(x);
// 	// ft_putnbr(y);
// }

t_image ft_new_sprite(void *mlx, char *path)
{
	t_image img;
	
	/* mlx function that creates and image that contains the xmp file found in the given path.
	* It also saves the width and height of the image in the pointers passed as parameters */
	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

static void	draw_walls(t_program *app)
{
	int	i;
	int	j;
	char **matrix;

	i = 0;
	j = 0;
	matrix = (*app).map.matrix;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == '1')
			{
				if ((*app).map.size.y == i + 1 || matrix[i + 1][j] != '1')
					mlx_put_image_to_window(app->mlx, app->window.reference,
					app->wall.wall_img_2, j * app->img_size, i * app->img_size);
				else
					mlx_put_image_to_window(app->mlx, app->window.reference,
					app->wall.wall_img_1, j * app->img_size, i * app->img_size);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	draw_eggs(t_program *app)
{
	int	i;
	int	j;
	char **matrix;

	i = 0;
	j = 0;
	matrix = (*app).map.matrix;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'C')
			{
				mlx_put_image_to_window(app->mlx, app->window.reference,
				app->egg.current_img, j * app->img_size, i * app->img_size);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	draw_exit(t_program *app)
{
	int	i;
	int	j;
	char **matrix;

	i = 0;
	j = 0;
	matrix = (*app).map.matrix;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'E')
			{
				mlx_put_image_to_window(app->mlx, app->window.reference,
				app->exit.exit_closed_img, j * app->img_size, i * app->img_size);
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	player_animation(t_player *player)
{
	if (player->counter > player->total_frames)
		player->current_img = player->player_img_1;
	else
		player->current_img = player->player_img_2;
	if (player->counter > player->total_frames * 2)
		player->counter = 0;
	player->counter += 1;
}

static void	egg_animation(t_egg *egg)
{
	if (egg->counter < egg->total_frames / 3)
		egg->current_img = egg->egg_img_1;
	else if (egg->counter <  egg->total_frames / 3 * 2)
		egg->current_img = egg->egg_img_2;
	else
		egg->current_img = egg->egg_img_3;
	if (egg->counter > egg->total_frames)
		egg->counter = 0;
	egg->counter += 1;
	
}

int	update(t_program *app)
{
	player_animation(&app->player);
	egg_animation(&app->egg);
	draw_walls(app);
	draw_eggs(app);
	draw_exit(app);
	mlx_string_put(app->mlx, app->window.reference, app->window.size.x - 32, 32, 0xFFFFFF, ft_itoa(app->moves));
	mlx_put_image_to_window(app->mlx, app->window.reference,
	app->player.current_img, app->player.position.x, app->player.position.y);
	return (1);
}

t_vector	get_player_position(t_map *map)
{
	t_vector position;
	int	i;
	int	j;
	char **matrix;
	
	i = 0;
	j = 0;
	matrix = map->matrix;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'P')
			{
				position.x = j * 64;
				position.y = i * 64;
				return (position);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	imgs_setup(t_program *app)
{
	app->egg.counter = 0;
	app->player.total_frames = 1500;
	app->egg.total_frames = 1500;
	app->player.position = get_player_position(&app->map);
	app->img_size = 64;
	app->player.player_img_1 = mlx_xpm_file_to_image(app->mlx,
			"sprites/player01.xpm", &app->img_size, &app->img_size);
	app->player.player_img_2 = mlx_xpm_file_to_image(app->mlx,
			"sprites/player02.xpm", &app->img_size, &app->img_size);
	app->wall.wall_img_1 = mlx_xpm_file_to_image(app->mlx,
	"sprites/wall1.xpm", &app->img_size, &app->img_size);
	app->wall.wall_img_2 = mlx_xpm_file_to_image(app->mlx,
	"sprites/wall2.xpm", &app->img_size, &app->img_size);
	app->egg.egg_img_1 = mlx_xpm_file_to_image(app->mlx,
	"sprites/egg1.xpm", &app->img_size, &app->img_size);
	app->egg.egg_img_2 = mlx_xpm_file_to_image(app->mlx,
	"sprites/egg2.xpm", &app->img_size, &app->img_size);
	app->egg.egg_img_3 = mlx_xpm_file_to_image(app->mlx,
	"sprites/egg3.xpm", &app->img_size, &app->img_size);
	app->exit.exit_open_img = mlx_xpm_file_to_image(app->mlx,
	"sprites/exitopen.xpm", &app->img_size, &app->img_size);
	app->exit.exit_closed_img = mlx_xpm_file_to_image(app->mlx,
	"sprites/exitclosed.xpm", &app->img_size, &app->img_size);
}


int	main(int argc, char *argv[])
{
	t_program	app;

	if (argc != 2)
		ft_printf(BRED"Error\nTry ./%s <map.ber>\n", argv[0], COLOR_RESET);
	else if (!is_map_valid(argv[1], &app.map))
		ft_printf(BRED"Error\nInvalid map\n", COLOR_RESET);
	else
	{
	app.mlx = mlx_init();
	app.window = new_window(app.mlx, app.map.size.x * 64 + 64, app.map.size.y * 64, "so_long");
	app.moves = 0;
	imgs_setup(&app);
	mlx_key_hook(app.window.reference, *control, &app);
	mlx_loop_hook(app.mlx, update, (void *)&app);
	mlx_loop(app.mlx);
	}
	return (0);
}
