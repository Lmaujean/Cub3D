/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:14:38 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/16 16:14:39 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_struc(t_game *game)
{
	int	i;

	i = 0;
	game->text.c = NULL;
	game->text.f = NULL;
	game->text.no = NULL;
	game->text.so = NULL;
	game->text.we = NULL;
	game->text.ea = NULL;
	game->map = NULL;
	while (i < 6)
	{
		game->texture[i] = NULL;
		i++;
	}

}

void	ft_freeallchar(t_game *game)
{
	int	i;

	i = 0;
	if (game->text.no)
		free(game->text.no);
	if (game->text.so)
		free(game->text.so);
	if (game->text.ea)
		free(game->text.ea);
	if (game->text.we)
		free(game->text.we);
	if (game->text.f)
		free(game->text.f);
	if (game->text.c)
		free(game->text.c);
	if (game->map)
		ft_freedouble(game->map);
	while (i < 6)
	{
		if (game->texture[i])
			free(game->texture[i]);
		i++;
	}
}

int	ft_error(int c, t_game *game)
{
	if (c == 1)
		printf("Error\nArguments\n");
	if (c == 2)
		printf("Error\nTry Open Directory\n");
	if (c == 3)
		printf("Error\nFile Not Found\n");
	if (c == 4)
		printf("Error\nFile Not .cub\n");
	if (c == 5)
		printf("Error\nWrong Parametre\n");
	if (c == 6)
		printf("Error\nBad Caractere On Map\n");
	if (c == 7)
		printf("Error\nPlayer Not Valid\n");
	if (c == 8)
		printf("Error\nMap Not Closed\n");
	if (c == 9)
		printf("Error\nFormat RGB Not valid\n");
	if (c == 10)
		printf("Error\nPath Not Valid\n");
	ft_freeallchar(game);
	return (c);
}
