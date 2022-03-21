#include "../includes/cub.h"

int	ft_close(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	exit(0);
}

void	set_pos(t_game *game, int keycode)
{
	if (keycode == KEY_W)
	{
		game->player.x += round(cos(game->player.angle) * 1);
		game->player.y += round(sin(game->player.angle) * 1);
	}
	if (keycode == KEY_D)
	{
		game->player.x += round(cos(game->player.angle + 90 * DR) * 1);
		game->player.y += round(sin(game->player.angle + 90 * DR) * 1);
	}
	if (keycode == KEY_S)
	{
		game->player.x -= round(cos(game->player.angle) * 1);
		game->player.y -= round(sin(game->player.angle) * 1);
	}
	if (keycode == KEY_A)
	{
		game->player.x += round(cos(game->player.angle - 90 * DR) * 1);
		game->player.y += round(sin(game->player.angle - 90 * DR) * 1);
	}
}

int	ft_press(int keycode, t_game *game)
{
	if (keycode == KEY_ECHAP)
	{
		ft_free_game(game);
		ft_close(0, game);
	}
	set_pos(game, keycode);
	if (keycode == KEY_ARROW_LEFT)
	{
		game->player.angle -= 0.1;
	}
	if (keycode == KEY_ARROW_RIGHT)
	{
		game->player.angle += 0.1;
	}
	return (0);
}
