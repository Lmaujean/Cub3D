/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:15:32 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/23 14:15:34 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_comp_str(char *str, char *str2)
{
	int	i;
	int	size;

	size = 0;
	size = ft_strlen(str2);
	i = 0;
	while (i < size)
	{
		if (str[i] != str2[i])
			return (0);
		else
			i++;
	}
	return (1);
}

int	ft_check_param_file(char *str)
{
	if ((ft_comp_str(str, "NO "))
		|| (ft_comp_str(str, "SO "))
		|| (ft_comp_str(str, "WE "))
		|| (ft_comp_str(str, "EA "))
		|| (ft_comp_str(str, "F "))
		|| (ft_comp_str(str, "C ")))
		return (1);
	return (0);
}
