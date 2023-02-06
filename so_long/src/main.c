/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:55:04 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/06 21:15:53 by lde-ross         ###   ########.fr       */
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

static void	open_player_imgs(t_program *app)
{
	app->player.idle_img_0 = mlx_xpm_file_to_image(app->mlx,
			"sprites/player01.xpm", &app->img_size.x, &app->img_size.y);
	app->player.idle_img_1 = mlx_xpm_file_to_image(app->mlx,
			"sprites/player02.xpm", &app->img_size.x, &app->img_size.y);
}

static void	draw_walls(t_program *app)
{
	int	i;
	int	j;
	char **matrix;
	void	*img1;
	void	*img2;
	int	*x;
	int	k;

	k = 64;
	x = &k;
	img1 = mlx_xpm_file_to_image(app->mlx,
	"sprites/wall1.xpm", &app->img_size.x, &app->img_size.y);
	img2 = mlx_xpm_file_to_image(app->mlx,
	"sprites/wall2.xpm", &app->img_size.x, &app->img_size.y);
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
					img2, j * 64, i * 64);
				else
					mlx_put_image_to_window(app->mlx, app->window.reference,
					img1, j * 64, i * 64);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_imgs(t_program *app)
{
	open_player_imgs(app);

}

static void	player_animation(t_player *player)
{
	// if (player->current_img == player->action_img
	// 	&& player->framecount >= player->action_frames)
	// {
	// 	player->current_img = player->idle_img_1;
	// }
	// else if (player->framecount == player->idle_frames)
	// {
	// 	player->current_img = player->idle_img_0;
	// }
	// else if (player->framecount >= player->idle_frames * 2)
	// {
	// 	player->current_img = player->idle_img_1;
	// 	player->framecount = 0;
	// }

	if (player->framecount > player->idle_frames)
		player->current_img = player->idle_img_1;
	else
		player->current_img = player->idle_img_0;
	if (player->framecount > player->idle_frames * 2)
		player->framecount = 0;
	player->framecount += 1;
}

int	update(t_program *app)
{
	player_animation(&app->player);
	draw_walls(app);
	mlx_put_image_to_window(app->mlx, app->window.reference,
	app->player.current_img, app->sprite_position.x, app->sprite_position.y);
	return (1);
}

static void	anim_setup(t_program *app)
{
	app->player.idle_frames = 150;
	app->player.action_frames = 10;
}

int	input(int key, void *param)
{
	t_program *app = (t_program *)param;

	// mlx function that clears the window
	mlx_clear_window(app->mlx, app->window.reference);

	// move in a direction based on the key
	if (key == 100)
		app->sprite_position.x += app->sprite.size.x;
	else if (key == 97)
		app->sprite_position.x -= app->sprite.size.x;
	else if (key == 115)
		app->sprite_position.y += app->sprite.size.y;
	else if (key == 119)
		app->sprite_position.y -= app->sprite.size.y;
	// change color based on keys R, G and B.

	// mlx function that puts and image into a window at a given position
	// (the position 0,0 is the upper-left corner)
	// mlx_put_image_to_window(app->mlx, app->window.reference,
	//	app->sprite.reference, app->sprite_position.x, app->sprite_position.y);

	// print the key pressed so you know the number of each key
	printf("Key pressed -> %d\n", key);
	return (0);
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
	app.window = new_window(app.mlx, app.map.size.x * 64, app.map.size.y * 64, "so_long");
	anim_setup(&app);
	init_imgs(&app);
	app.sprite_position.x = 64;
	app.sprite_position.y = 64;
	app.sprite.size.x = 64;
	app.sprite.size.y = 64;
	mlx_key_hook(app.window.reference, *input, &app);
	mlx_loop_hook(app.mlx, update, (void *)&app);
	// hooks(&app);
	mlx_loop(app.mlx);
	}
	return (0);
}
