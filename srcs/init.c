#include "../includes/cub.h"

int	init_minilibx(t_game *game)
{
	game->init_mlx = NULL;
	game->init_window = NULL;
	game->init_mlx = mlx_init();
	game->player.x = 3 * 64;
	game->player.y = 4 * 64;
	game->player.angle = 45 * DR;
	if (!game->init_mlx)
		return (0);
	game->init_window = mlx_new_window(game->init_mlx, WIDTH, HEIGTH, "Cub3D");
	if (!game->init_window)
		return (0);
	return (1);
	// if (ft_init_img(game) == 0)
	// 	return (0);
	// return (1);
}