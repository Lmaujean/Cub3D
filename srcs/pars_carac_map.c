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

void	add_space(char **line, int space)
{
	char	*tmp;
	char	*tmp_space;

	tmp_space = ft_calloc(sizeof(char *), space + 1);
	while (space-- > 0)
		tmp_space[space] = ' ';
	tmp = ft_strjoin(*line, tmp_space);
	free(*line);
	free(tmp_space);
	*line = tmp;
}

int	size_line(t_game *game)
{
	int	max;
	int	i;

	max = 0;
	i = -1;
	while (game->map[++i])
	{
		if (ft_strlen(game->map[i]) > max)
			max = ft_strlen(game->map[i]);
	}
	return (max);
}

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
	int			i;
	int			j;
	const int	size = size_line(game);
	int			z;

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
	z = -1;
	while (game->map[++z])
		add_space(&game->map[z], size - ft_strlen(game->map[z]));
	ft_check_nbr_carac(game);
}
