/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:54:15 by ybouali           #+#    #+#             */
/*   Updated: 2022/02/07 04:46:38 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_table(char **table)
{
	int	i;

	i = -1;
	while (table[++i])
		free(table[i]);
	free(table);
}

int	ft_get_length_of_map(char **table)
{
	int	i;

	i = 0;
	while (table[i])
		i++;
	return (i);
}

void	ft_err_exit(char *str, char **table, void *buff, t_long *m)
{
	if (table != NULL)
		ft_free_table(table);
	ft_putstr_fd(str, 1);
	if (buff != NULL)
		free (buff);
	if (m != NULL)
	{
		mlx_clear_window(m->p, m->m_w);
		mlx_destroy_window(m->p, m->m_w);
		free(m);
	}
	exit(1);
}
