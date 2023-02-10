/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:55:04 by lde-ross          #+#    #+#             */
/*   Updated: 2023/02/10 17:13:54 by lde-ross         ###   ########.fr       */
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
				{
					if (i == 0 && j == 0)
						mlx_put_image_to_window(app->mlx, app->window.reference,
						app->wall.frame_img, j * app->img_size, i * app->img_size);
					else
						mlx_put_image_to_window(app->mlx, app->window.reference,
						app->wall.wall_img_1, j * app->img_size, i * app->img_size);
				}
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

void	move_enemy(t_program *app)
{
	char **matrix;
	int	move;
	
	move = random_number();
	matrix = app->map.matrix;
	if (move == 0 && matrix[app->enemy.position.y][app->enemy.position.x + 1] == '0')
	{
		app->enemy.position.x++;
	}
	else if (move == 1 && matrix[app->enemy.position.y][app->enemy.position.x - 1] == '0')
	{
		app->enemy.position.x--;
	}
	else if (move == 2 && matrix[app->enemy.position.y + 1][app->enemy.position.x] == '0')
	{
		app->enemy.position.y++;
	}
	else if (move == 3 && matrix[app->enemy.position.y - 1][app->enemy.position.x] == '0')
	{
		app->enemy.position.y--;
	}
	else
		move_enemy(app);
}

static void	draw_enemy(t_program *app)
{
	static int	move = 1000;
	
	if (move < 0)
	{
		move_enemy(app);
			mlx_clear_window(app->mlx, app->window.reference);
		move = 1000;
	}
	move--;
	mlx_put_image_to_window(app->mlx, app->window.reference,
		app->enemy.current_img, app->enemy.position.x * app->img_size, app->enemy.position.y * app->img_size);
}

static void	draw_hearts(t_program *app)
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
			if (i != app->exit.exit_vector.y || j != app->exit.exit_vector.x)
			{
				mlx_put_image_to_window(app->mlx, app->window.reference,
				app->heart.current_img, j * app->img_size, i * app->img_size);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	draw_exit(t_program *app)
{
	char **matrix;
	t_vector	vector;

	vector = app->exit.exit_vector;
	matrix = (*app).map.matrix;
	if (app->collected)
	{
		mlx_put_image_to_window(app->mlx, app->window.reference,
		app->exit.exit_open_img, vector.x * app->img_size, vector.y * app->img_size);
	}
	else
	{
		mlx_put_image_to_window(app->mlx, app->window.reference,
		app->exit.exit_closed_img, vector.x * app->img_size, vector.y * app->img_size);
	}
		return ;
}

void	finish_game(t_program *app)
{
	ft_printf("%d finish", app->moves);
}

void	check_finish(t_program *app)
{
	if (app->player.position.y / app->img_size == app->exit.exit_vector.y && app->player.position.x / app->img_size == app->exit.exit_vector.x)
		app->finish = true;
	if (all_eggs_collected(app))
		open_exit(app);

}

int random_number(void) {
    static unsigned int seed = 1;
    seed = 1103515245 * seed + 12345;
    return (unsigned int)(seed / 65536) % 32768 % 4;
}

void	print_matrix(t_program *app)
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
			ft_printf("%c", matrix[i][j]);
			j++;
		}
		j = 0;
		ft_printf("\n");
		i++;
	}
	ft_printf("\n\n\n");
}

t_bool	game_over(t_program *app)
{
	if (app->enemy.position.x == app->player.position.x / 64 && app->enemy.position.y == app->player.position.y / 64)
		return (true);
	return (false);

}

int	update(t_program *app)
{
	char	*moves;

	check_finish(app);	
	player_animation(app);
	ft_printf("enemy x: %d enemy y: %d\n", app->enemy.position.x, app->enemy.position.y);
	ft_printf("player x: %d player y: %d\n", app->player.position.x, app->player.position.y);
	if (game_over(app))
		close_app(app);
	else if (!app->finish)
	{
		moves = ft_itoa(app->moves);
		egg_animation(&app->egg);
		enemy_animation(app);
		draw_walls(app);
		draw_exit(app);
		draw_eggs(app);
		draw_enemy(app);
		mlx_string_put(app->mlx, app->window.reference, app->img_size / 2 - 2, app->img_size / 2, 0xFFFFFF, moves);
		//print_matrix(app);
		free(moves);
	}
	else
	{
		heart_animation(&app->heart);
		draw_hearts(app);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_program	app;

	if (argc != 2)
		invalid_args(argv[0]);
	else if (!map_is_valid(argv[1], &app.map))
		invalid_map(&app.map);
	else
	{
		init_game(&app);
		mlx_hook(app.window.reference, 17, 0, close_app, (void *)&app);
		mlx_key_hook(app.window.reference, *control, (void *)&app);
		mlx_loop_hook(app.mlx, update, (void *)&app);
		mlx_loop(app.mlx);
	}
	return (0);
}
