/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:55:04 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/05 19:24:04 by lde-ross         ###   ########.fr       */
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
			"sprites/player_01.xpm", &app->img_size.x, &app->img_size.y);
	app->player.idle_img_1 = mlx_xpm_file_to_image(app->mlx,
			"sprites/player_02.xpm", &app->img_size.x, &app->img_size.y);
	app->player.action_img = mlx_xpm_file_to_image(app->mlx,
			"sprites/player_03.xpm", &app->img_size.x, &app->img_size.y);
	app->player.current_img = app->player.action_img;
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
	 mlx_put_image_to_window(app->mlx, app->window.reference,
	app->player.current_img, app->sprite_position.x, app->sprite_position.y);
	return (1);
}

static void	anim_setup(t_program *app)
{
	app->player.idle_frames = 15000;
	app->player.action_frames = 10;
}

int	main(void)
{
	t_program	app;
	ft_printf("Hi");
	app.mlx = mlx_init();
	app.window = new_window(app.mlx, 1980, 1080, "so_long");
	anim_setup(&app);
	init_imgs(&app);
	// app.sprite = ft_new_sprite(app.mlx, "sprite_0.xpm");
	app.sprite_position.x = 500;
	app.sprite_position.y = 500;
	// mlx_put_image_to_window(app.mlx, app.window.reference,
	// app.sprite.reference, app.sprite_position.x, app.sprite_position.y);
	mlx_loop_hook(app.mlx, update, (void *)&app);
	// hooks(&app);
	mlx_loop(app.mlx);
}
