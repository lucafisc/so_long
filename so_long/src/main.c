/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:55:04 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/04 17:57:47 by lde-ross         ###   ########.fr       */
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

int	main(void)
{
	t_program	app;
	ft_printf("Hi");
	app.mlx = mlx_init();
	app.window = new_window(app.mlx, 1980, 1080, "so_long");
	draw_square(&app, 640 / 2, 360 / 2, 200, 100, 0xFFFFFF);
	draw_square(&app, 630 / 2, 320 / 2, 100, 50, 0xFFC0CB);
	// app.sprite = ft_new_sprite(app.mlx, "block.xpm");
	//app.sprite_position.x = 0;
	//app.sprite_position.y = 0;
	// mlx_put_image_to_window(app.mlx, app.window.reference,
	// app.sprite.reference, app.sprite_position.x, app.sprite_position.y);
	// hooks(&app);
	mlx_loop(app.mlx);
}
