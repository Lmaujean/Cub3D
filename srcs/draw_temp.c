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


void	draw_pixel(t_game *game, int x, int y, unsigned int color)
{
	int	a;
	int	b;

	a = x;
	while (a < x + 32)
	{
		b = y;
		while (b < y + 32)
		{
			my_mlx_pixel_put(game, b, a, color);
			b++;
		}
		a++;
	}
}

unsigned int	ft_get_color(t_game *game, int i, int j)
{
	if (game->map[i][j] && game->map[i][j] == '1')
		return (0x00FFFFFF);
	if (game->map[i][j] && game->map[i][j] == '0')
		return (0x00000000);
	if (game->map[i][j] && game->map[i][j] == 'N')
		return (0x00FFFF00);
	else
		return (0x00800000);
}

void	ft_draw(t_game *game)
{
	int				i;
	int				j;
	t_img			img;
	unsigned int	color;

	game->img = &img;
	game->img->data.data = mlx_new_image(game->init_mlx, WIDTH, HEIGTH);
	game->img->data.addr = mlx_get_data_addr(game->img->data.data, \
							&game->img->data.bits_per_pixel, &game->img->data.line_length, &game->img->data.endian);
	i = 0;
	game->x = -1;
	while (++game->x < 16)
	{
		j = 0;
		game->y = -1;
		while (++game->y < 40)
		{
			color = ft_get_color(game, game->x, game->y);
			draw_pixel(game, i, j, color);
			j += 32;
		}
		i += 32;
	}
	mlx_put_image_to_window(game->init_mlx, game->init_window, game->img->data.data, 0, 0);
}