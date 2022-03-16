/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:43:08 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/14 13:43:10 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_check_nbr_carac(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' || \
				game->map[i][j] == 'E' || game->map[i][j] == 'W')
				count++;
		}
	}
	if (count > 1 || count < 1)
	{
		ft_error(7);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_carac_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' && \
				game->map[i][j] != ' ' && game->map[i][j] != 'N' && \
				game->map[i][j] != 'S' && game->map[i][j] != 'W' && \
				game->map[i][j] != 'E')
			{
				ft_error(6);
				exit(EXIT_FAILURE);
			}
		}
	}
	ft_check_nbr_carac(game);
}
