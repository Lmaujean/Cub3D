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

int	ft_error(int c)
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
	{
		printf("Error\nWrong Parametre\n");
		exit(EXIT_FAILURE);
	}
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
	return (c);
}
