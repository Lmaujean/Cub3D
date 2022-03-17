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
	}
	ft_freeallchar(&game);
	return (0);
}
