#include "../includes/cub.h"

void	create_img(t_img *img, void *mlx_img)
{
	img->img = mlx_img;
	img->data.addr = mlx_get_data_addr(mlx_img, &img->data.bits_per_pixel,
			&img->data.line_length, &img->data.endian);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

unsigned int	mlx_get_pixel_img(const t_img *img, int x, int y)
{
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	return (*(unsigned int *)(img->data.addr
		+ (y * img->data.line_length + x * (img->data.bits_per_pixel / 8))));
}

void	mlx_put_img_to_img(t_img *dest, const t_img *src, int x, int y)
{
	int		current_x;
	int		current_y;

	current_y = 0;
	current_x = 0;
	while (current_y < src->height)
	{
		current_x = 0;
		while (current_x < src->width)
		{
			mlx_put_pixel_to_img(dest, current_x + x, current_y + y,
				mlx_get_pixel_img(src, current_x, current_y));
			current_x++;
		}
		current_y++;
	}
}

void	mlx_put_pixel_to_img(t_img *dest, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x >= dest->width || y < 0 || y >= dest->height)
		return ;
	if (color == 0xFF000000)
		return ;
	dst = dest->data.addr + (y * dest->data.line_length
			+ x * (dest->data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
