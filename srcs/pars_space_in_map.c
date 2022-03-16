/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_space_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:32:20 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/14 17:32:40 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_check_last_line(t_game *game)
{
	int	size;
	int	i;
	int	j;

	size = ft_tab_len(game->map);
	i = size - 1;
	if (game->map)
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != ' ')
			{
				ft_error(8);
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	ft_check_before_line(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if ((game->map[i][j] == '0' || game->map[i][j] == 'N' || \
				game->map[i][j] == 'S' || game->map[i][j] == 'W' || \
				game->map[i][j] == 'E') && game->map[i - 1][j])
			{
				if (game->map[i - 1][j] != '0' && game->map[i - 1][j] != '1' && \
					game->map[i - 1][j] != 'S' && game->map[i - 1][j] != 'N' && \
					game->map[i - 1][j] != 'E' && game->map[i - 1][j] != 'W')
				{
					ft_error(8);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}

void	ft_check_next_line(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i + 1] == NULL)
				break ;
			if ((game->map[i][j] == '0' || game->map[i][j] == 'N' || \
				game->map[i][j] == 'S' || game->map[i][j] == 'W' || \
				game->map[i][j] == 'E') && game->map[i + 1][j])
			{
				if (game->map[i + 1][j] != '0' && game->map[i + 1][j] != '1' && \
					game->map[i + 1][j] != 'S' && game->map[i + 1][j] != 'N' && \
					game->map[i + 1][j] != 'E' && game->map[i + 1][j] != 'W')
				{
					ft_error(8);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}

void	ft_check_all_file(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if ((game->map[i][j] == '0' || game->map[i][j] == 'N' || \
				game->map[i][j] == 'S' || game->map[i][j] == 'W' || \
				game->map[i][j] == 'E') && game->map[i][j + 1])
			{
				if (game->map[i][j + 1] != '0' && game->map[i][j + 1] != '1' && \
					game->map[i][j + 1] != 'S' && game->map[i][j + 1] != 'N' && \
					game->map[i][j + 1] != 'E' && game->map[i][j + 1] != 'W')
				{
					ft_error(8);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	ft_check_before_line(game);
}

void	ft_check_first_line(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->map[i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != ' ')
			{
				ft_error(8);
				exit(EXIT_FAILURE);
			}
		}
	}
	ft_check_next_line(game);
	ft_check_last_line(game);
	ft_check_first_carac(game);
	ft_check_all_file(game);
}
