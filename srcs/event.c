#include "../includes/cub.h"

int	ft_close(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	exit(0);
}

int	ft_press(int keycode, t_game *game)
{

	if (keycode == KEY_ECHAP)
	{
        ft_free_game(game);
		ft_close(0, game);
	}
    return (0);
}