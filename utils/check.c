/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:06:38 by ybouali           #+#    #+#             */
/*   Updated: 2022/02/07 05:06:54 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_check_len(char **line_of_map)
{
	int		i;
	int		j;
	char	*msg1;

	i = -1;
	msg1 = "Error\nIn length of lines of map";
	while (line_of_map[++i] != 0)
	{
		j = -1;
		while (line_of_map[++j] != 0)
		{
			if (i == j)
				j++;
			if (line_of_map[j] == 0)
				break ;
			if (ft_bufflen(line_of_map[i]) != ft_bufflen(line_of_map[j]))
				ft_err_exit(msg1, line_of_map, NULL, NULL);
		}
	}
}

char	**ft_check_line_map(char *name_map)
{
	char	**lines_of_map;
	int		i;

	ft_check_name_map(name_map);
	lines_of_map = ft_stock_table(name_map);
	if (lines_of_map[0] == 0 || lines_of_map[0][0] == '\n'
			|| lines_of_map[0][0] == ' ')
		ft_err_exit("Error\nInvalid map", lines_of_map, NULL, NULL);
	ft_check_len(lines_of_map);
	i = ft_get_length_of_map(lines_of_map);
	if (ft_check_first_last(lines_of_map[0]) != 1)
		ft_err_exit("Error\nIn the first line", lines_of_map, NULL, NULL);
	ft_check_middle_lines(lines_of_map);
	if (ft_check_first_last(lines_of_map[i - 1]) != 1)
		ft_err_exit("Error\nIn the last line", lines_of_map, NULL, NULL);
	return (lines_of_map);
}
