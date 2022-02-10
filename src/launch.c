/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:18:53 by ybouali           #+#    #+#             */
/*   Updated: 2022/02/07 06:07:33 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	e(void *m)
{
	(void)m;
	exit (1);
	return (1);
}

void	ft_launch(t_long *m)
{
	m->c_m = 0;
	m->k = 0;
	m->height = ft_get_length_of_map(m->lom) * 50;
	m->width = ft_bufflen(m->lom[0]) * 50;
	m->p = mlx_init();
	m->m_w = mlx_new_window(m->p, m->width, m->height + 30, "SO_LONG");
	ft_stock_img(m);
	mlx_hook(m->m_w, 17, 0L, e, m);
	mlx_key_hook(m->m_w, event, m);
	mlx_loop_hook(m->p, animation, m);
	mlx_loop(m->p);
}
