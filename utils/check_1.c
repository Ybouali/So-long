/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:55:11 by ybouali           #+#    #+#             */
/*   Updated: 2022/02/07 05:21:27 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_check_c_p_e(int *err, char **lines_of_map)
{
	char	*msg1;
	char	*msg2;
	char	*msg3;

	msg1 = "Error\nIn the map it should be one player no more";
	msg2 = "Error\nIn the map it should be at least one coin";
	msg3 = "Error\nIn the map it should be one exit port ro more";
	if (err[2] != 1)
		ft_err_exit(msg1, lines_of_map, err, NULL);
	else if (err[0] == 0)
		ft_err_exit(msg2, lines_of_map, err, NULL);
	else if (err[1] == 0)
		ft_err_exit(msg3, lines_of_map, err, NULL);
	else
		free(err);
}

static int	ft_help(char *line, int i, int *err)
{
	if (line[i] && line[i] == 'C')
	{
		err[0] += 1;
		return (1);
	}
	else if (line[i] && line[i] == 'E')
	{
		err[1] += 1;
		return (1);
	}
	else if (line[i] && line[i] == 'P')
	{
		err[2] += 1;
		return (1);
	}
	else if (line[i] && line[i] == 'W')
		return (1);
	else if (line[i] && line[i] == '1')
		return (1);
	else if (line[i] && line[i] == '0')
		return (1);
	else
		return (0);
}	

static void	ft_check_str(char **table, int *err)
{
	int		i;
	int		len;
	char	*msg1;
	int		j;

	msg1 = "Error\nIn the characters of map";
	i = 0;
	len = ft_get_length_of_map(table);
	while (++i < (len - 1))
	{
		j = 0;
		while (++j < ft_bufflen(table[i]) - 1)
		{	
			if (ft_help(table[i], j, err) == 0)
				ft_err_exit(msg1, table, NULL, NULL);
		}
	}
}

static void	ft_help_2(int i, char **lines_of_map)
{
	char	*msg1;

	msg1 = "Error\nThe first character and last one should be 1 in line";
	if (lines_of_map[i][0] != '1')
		ft_err_exit(msg1, lines_of_map, NULL, NULL);
	if (lines_of_map[i][ft_bufflen(lines_of_map[i]) - 1] != '1')
		ft_err_exit(msg1, lines_of_map, NULL, NULL);
}

void	ft_check_middle_lines(char **lines_of_map)
{
	int		i;
	int		*err;
	int		len;

	err = (int *)malloc(sizeof(int) * 3);
	if (!err)
		ft_err_exit("Error\nMalloc error", lines_of_map, NULL, NULL);
	ft_bzero(err, sizeof(int) * 3);
	len = ft_get_length_of_map(lines_of_map);
	i = 0;
	while (++i < (len - 1))
		ft_help_2(i, lines_of_map);
	ft_check_str(lines_of_map, err);
	ft_check_c_p_e(err, lines_of_map);
}
