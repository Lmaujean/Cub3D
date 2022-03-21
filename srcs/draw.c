#include "../includes/cub.h"

void plotLineWidth(t_game *data, int x0, int y0, int x1, int y1, float wd, int color)
{
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx - dy, e2, x2, y2; /* error value e_xy */
	float ed = dx + dy == 0 ? 1 : sqrt((float)dx * dx + (float)dy * dy);

	for (wd = (wd + 1) / 2;;)
	{ /* pixel loop */
		my_mlx_pixel_put(data, x0, y0, color);
		e2 = err;
		x2 = x0;
		if (2 * e2 >= -dx)
		{ /* x step */
			for (e2 += dy, y2 = y0; e2 < ed * wd && (y1 != y2 || dx > dy); e2 += dx)
				my_mlx_pixel_put(data, x0, y2 += sy, color);
			if (x0 == x1)
				break;
			e2 = err;
			err -= dy;
			x0 += sx;
		}
		if (2 * e2 <= dy)
		{ /* y step */
			for (e2 = dx - e2; e2 < ed * wd && (x1 != x2 || dx < dy); e2 += dy)
				my_mlx_pixel_put(data, x2 += sx, y0, color);
			if (y0 == y1)
				break;
			err += dx;
			y0 += sy;
		}
	}
}

// static int	ft_error_failure(t_game *game)
// {
// 	printf("Error\nPas Content\n");
// 	ft_free_game(game);
// 	return(EXIT_FAILURE);
// }

// int	ft_init_img(t_game *game)
// {
// 	int			i;
// 	const char	*tab[] = {WALL_NORD, WALL_SUD, WALL_EST, WALL_WEST};

// 	game->img = ft_calloc(sizeof(t_img), NBR_IMG);
// 	if (!game->img)
// 		return (0);
//     game->img[0].img = mlx_new_image(game->init_mlx, WIDTH, HEIGTH);
//     game->img[0].data.addr = mlx_get_data_addr(game->img[0].img, \
//     &game->img->data.bits_per_pixel, &game->img->data.line_length, \
//     &game->img->data.endian);
// 	if (game->img[0].img == NULL)
// 		exit(ft_error_failure(game));
// 	i = 1;
// 	while (i < NBR_IMG)
// 	{
// 		game->img[i].img = mlx_xpm_file_to_image(game->init_mlx,
// 				(char *)tab[i - 1], &game->img[i].width, &game->img[i].height);
// 		if (game->img[i].img == NULL)
// 			exit(ft_error_failure(game));
// 		i++;
// 	}
// 	return (1);
// }
