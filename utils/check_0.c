/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:18:31 by ybouali           #+#    #+#             */
/*   Updated: 2022/02/07 04:59:28 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**ft_allocate_table(char *name)
{
	char	*line;
	char	**lines;
	int		fd;
	int		len;

	len = 0;
	fd = open (name, O_RDONLY);
	if (fd < -1)
		ft_err_exit("Error\nIn fd file", NULL, NULL, NULL);
	line = get_next_line(fd);
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	lines = (char **)malloc(sizeof(char *) * (len + 1));
	if (!lines)
		return (NULL);
	return (lines);
}

char	**ft_stock_table(char *name)
{
	char	*line;
	char	**lines;
	int		fd;
	int		i;

	i = -1;
	lines = ft_allocate_table(name);
	fd = open (name, O_RDONLY);
	if (fd < -1)
		ft_err_exit("Error\nIn fd file", NULL, NULL, NULL);
	line = get_next_line(fd);
	while (line)
	{
		lines[++i] = line;
		line = get_next_line(fd);
	}
	lines[++i] = 0;
	return (lines);
}

void	ft_check_name_map(char *name_map)
{
	int	len;

	len = ft_strlen(name_map);
	if (ft_strcmp(((name_map + len) - 4), ".ber", 4) == 0)
		ft_err_exit("Error\nInvalide name of map", NULL, NULL, NULL);
}

int	ft_check_first_last(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] && line[i] == '\n')
			break ;
		if (line[i] && line[i] != '1')
			return (0);
	}
	return (1);
}
