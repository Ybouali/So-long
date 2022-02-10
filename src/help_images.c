/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:27:59 by ybouali           #+#    #+#             */
/*   Updated: 2022/02/07 06:02:27 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	help_1(t_long *m)
{
	if (m->lom[m->i][m->j] == '1')
	{
		mlx_put_image_to_window(m->p, m->m_w, m->wall, m->w, m->h);
		m->w += 50;
		m->j++;
	}
	if (m->lom[m->i][m->j] == 'P')
	{
		mlx_put_image_to_window(m->p, m->m_w, m->player, m->w, m->h);
		m->p_x_player = m->i;
		m->p_y_player = m->j;
		m->w += 50;
		m->j++;
	}
	if (m->lom[m->i][m->j] == 'C')
	{
		m->c_coin++;
		mlx_put_image_to_window(m->p, m->m_w, m->coin, m->w, m->h);
		m->w += 50;
		m->j++;
	}
}

static void	help_2(t_long *m)
{
	if (m->lom[m->i][m->j] == 'E')
	{
		mlx_put_image_to_window(m->p, m->m_w, m->exit, m->w, m->h);
		m->w += 50;
		m->j++;
	}
	if (m->lom[m->i][m->j] == 'W')
	{
		if (m->lom[m->i][m->j - 1] == 'P' || m->lom[m->i][m->j + 1] == 'P')
			ft_err_exit("GAME OVER (LOSER)\n", m->lom, NULL, m);
		mlx_put_image_to_window(m->p, m->m_w, m->monster, m->w, m->h);
		m->w += 50;
		m->j++;
	}
	if (m->lom[m->i][m->j] == '0')
	{
		mlx_put_image_to_window(m->p, m->m_w, m->back, m->w, m->h);
		m->j++;
		m->w += 50;
	}
}

void	images(t_long *m)
{
	ft_put_str(m);
	m->c_coin = 0;
	m->h = 30;
	m->i = 0;
	while (m->h < m->height)
	{
		m->w = 0;
		m->j = 0;
		while (m->w < m->width)
		{
			help_1(m);
			help_2(m);
		}
		m->h += 50;
		m->i++;
	}
}
