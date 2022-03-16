/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:05:03 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/16 11:05:04 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_check_int_c(t_game *game)
{
	char	**split;
	int		ret;
	int		i;

	split = ft_split(game->text.c, ',');
	i = -1;
	while (split[++i])
	{
		ret = ft_atoi(split[i]);
		if (ret < 0 || ret > 255)
		{
			ft_error(9);
			exit(EXIT_FAILURE);
		}
	}
	ft_freedouble(split);
}

void	ft_check_int_f(t_game *game)
{
	char	**split;
	int		ret;
	int		i;

	split = ft_split(game->text.f, ',');
	i = -1;
	while (split[++i])
	{
		ret = ft_atoi(split[i]);
		if (ret < 0 || ret > 255)
		{
			ft_error(9);
			exit(EXIT_FAILURE);
		}
	}
	ft_freedouble(split);
	ft_check_int_c(game);
	valid_path_texture(game->text.no);
	valid_path_texture(game->text.ea);
	valid_path_texture(game->text.we);
	valid_path_texture(game->text.so);
}

void	valid_path_texture(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_error(10);
		exit(EXIT_FAILURE);
	}
	close(fd);
}
