#include "../includes/cub.h"

int	ft_init_img(t_game *game)
{
	int			i;
	const char	*tab[] = {WALL_NORD, WALL_SUD, WALL_EST, WALL_WEST};

	game->img = ft_calloc(sizeof(t_img), NBR_IMG);
	if (!game->img)
		return (0);
    game->img[0].img = mlx_new_image(game->init_mlx, WIDTH, HEIGTH);
    game->img[0].data.addr = mlx_get_data_addr(game->img[0].img, \
    &game->img->data.bits_per_pixel, &game->img->data.line_length, \
    &game->img->data.endian);
	i = 1;
	while (i < NBR_IMG)
	{
		game->img[i].img = mlx_xpm_file_to_image(game->init_mlx,
				(char *)tab[i - 1], &game->img[i].width, &game->img[i].height);
		i++;
	}
	return (1);
}