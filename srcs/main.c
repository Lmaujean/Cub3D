/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:37:03 by lmaujean          #+#    #+#             */
/*   Updated: 2022/02/28 10:37:04 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	launch_game(t_game *game)
{
	mlx_hook(game->init_window, 17, 0, ft_close, game);
	mlx_hook(game->init_window, 2, 1L << 0, ft_press, game);
	mlx_loop(game->init_mlx);
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;

	init_struc(&game);
	fd = ft_valid_fd(av[1], ac);
	if (fd)
	{
		ft_valid_file(av[1]);
		ft_get_param(fd, av[1], &game);
		ft_check_carac_map(&game);
		ft_check_first_line(&game);
		if (!init_minilibx(&game))
		{
			printf("Error:\n");
			ft_free_game(&game);
			exit(EXIT_FAILURE);
		}
		launch_game(&game);
	}
	ft_free_game(&game);
	return (0);
}
