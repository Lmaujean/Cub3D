/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:30:23 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/20 22:30:25 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	my_mlx_pixel_put(t_game *env, int x, int y, unsigned int color)
{
	char	*dst;

	dst = env->img->data.addr + (y * env->img->data.line_length + x * \
			(env->img->data.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	ft_draw_background(t_game *game, int color)
{
	int	x = 0;
	int	y = 0;

	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			my_mlx_pixel_put(game, x, y, color);
			y++;
		}
		x++;
	}
}

void	ft_square(t_game *game, int x0, int y0, int x1, int y1, int color)
{
	int	i = x0;
	int j = y0;

	while (i < x1)
	{
		j = y0;
		while (j < y1)
		{
			my_mlx_pixel_put(game, i, j, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_map2d(t_game *game)
{
	int i = 0;
	int j = 0;
	int MapTile = 64;
	int MapX = game->line.x;
	int MapY = game->line.y;

	while (i < MapY)
	{
		j = 0;
		while (j < MapX)
		{
			if (game->map[i][j] == '1')
				ft_square(game, i * MapTile + 1, j * MapTile + 1, (i + 1) * MapTile - 1, (j + 1) * MapTile - 1, 0x000000FF);
			else
				ft_square(game, i * MapTile + 1, j * MapTile + 1, (i + 1) * MapTile - 1, (j + 1) * MapTile - 1, 0x0000FF00);
			j++;
		}
		i++;
	}
}

void	ft_draw_player(t_game *game)
{
	ft_square(game, game->player.x, game->player.y, game->player.x + 5, game->player.y + 5, 0xF0E68C);
}

void	ft_draw_ply_angle(t_game *game)
{
	plotLineWidth(game, game->player.x, game->player.y, game->player.x + (int)(round(cos(game->player.angle) * 15)), game->player.y + (int)(round(sin(game->player.angle) * 15)), 1.0, 0x00FF0000);
}

int	ft_draw(t_game *game)
{
	t_img			img;

	game->img = &img;
	game->img->data.data = mlx_new_image(game->init_mlx, WIDTH, HEIGTH);
	game->img->data.addr = mlx_get_data_addr(game->img->data.data, \
							&game->img->data.bits_per_pixel, &game->img->data.line_length, &game->img->data.endian);
	ft_draw_background(game, 0xA9A9A9);
	ft_draw_map2d(game);
	ft_draw_player(game);
	ft_draw_ply_angle(game);
	mlx_put_image_to_window(game->init_mlx, game->init_window, game->img->data.data, 0, 0);
	mlx_destroy_image(game->init_mlx, game->img->data.data);
	return (0);
}
