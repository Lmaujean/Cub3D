/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:38:55 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/11 10:38:59 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_valid_fd(char *str, int ac)
{
	int	fd;

	if (ac != 2)
	{
		ft_error(1);
		exit(EXIT_FAILURE);
	}
	fd = open(str, O_DIRECTORY);
	if (fd != -1)
	{
		ft_error(2);
		exit(EXIT_FAILURE);
	}
	close(fd);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_error(3);
		close(fd);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	ft_valid_file(char *str)
{
	if (!ft_check_ext(str, ".cub"))
	{
		ft_error(4);
		exit(EXIT_FAILURE);
	}
}

char	**ft_get_file(int fd, const char *str)
{
	char	**file;
	int		y;
	char	*line;
	int		i;
	int		ret;

	line = NULL;
	y = 0;
	while (get_next_line(fd, &line))
	{
		if (*line)
			y++;
		free(line);
	}
	y++;
	free(line);
	close(fd);
	fd = open(str, O_RDONLY);
	file = malloc(sizeof(char *) * (y + 1));
	i = 0;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (*line)
		{
			file[i] = ft_strdup(line);
			i++;
		}
		free(line);
	}
	file[i] = NULL;
	close(fd);
	return (file);
}

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
