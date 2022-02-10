/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:13:56 by ybouali           #+#    #+#             */
/*   Updated: 2022/02/07 06:03:44 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_player(t_long *m, int i, int j)
{
	if (m->lom[i][j] == 'W')
	{
		if (m->c_coin > 0)
			ft_err_exit("GAME OVER (LOSER)\n", m->lom, NULL, m);
		return (0);
	}
	else if (m->lom[i][j] == 'E')
	{
		if (m->c_coin == 0)
			ft_err_exit("GAME OVER (WIN)\n", m->lom, NULL, m);
		return (0);
	}
	else if (m->lom[i][j] == '1')
		return (0);
	return (1);
}

static void	ft_p_x_player(t_long *m, int x, int y, int k)
{
	if (move_player(m, k, m->p_y_player) == 1)
	{
		m->c_m++;
		m->lom[x][y] = '0';
		m->lom[k][y] = 'P';
	}
}

static void	ft_p_y_player(t_long *m, int x, int y, int k)
{
	if (move_player(m, m->p_x_player, k) == 1)
	{
		m->c_m++;
		m->lom[x][y] = '0';
		m->lom[x][k] = 'P';
	}
}

int	event(int key, t_long *m)
{
	if (key == 126 || key == 13)
		ft_p_x_player(m, m->p_x_player, m->p_y_player, m->p_x_player - 1);
	else if (key == 125 || key == 1)
		ft_p_x_player(m, m->p_x_player, m->p_y_player, m->p_x_player + 1);
	else if (key == 124 || key == 2)
		ft_p_y_player(m, m->p_x_player, m->p_y_player, m->p_y_player + 1);
	else if (key == 123 || key == 0)
		ft_p_y_player(m, m->p_x_player, m->p_y_player, m->p_y_player - 1);
	else if (key == 53)
		ft_err_exit("", m->lom, NULL, m);
	images(m);
	return (1);
}
