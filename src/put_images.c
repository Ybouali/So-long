/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:53:27 by ybouali           #+#    #+#             */
/*   Updated: 2022/02/07 04:05:10 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_stock_img(t_long *m)
{
	m->monster = mlx_xpm_file_to_image(m->p, "./img/enemy.xpm", &m->w, &m->h);
	m->wall = mlx_xpm_file_to_image(m->p, "./img/border.xpm", &m->w, &m->h);
	m->coin = mlx_xpm_file_to_image(m->p, "./img/coin_b.xpm", &m->w, &m->h);
	m->player = mlx_xpm_file_to_image(m->p, "./img/player.xpm", &m->w, &m->h);
	m->back = mlx_xpm_file_to_image(m->p, "./img/background.xpm", &m->w, &m->h);
	m->header = mlx_xpm_file_to_image(m->p, "./img/header.xpm", &m->w, &m->h);
	m->exit = mlx_xpm_file_to_image(m->p, "./img/Door.xpm", &m->w, &m->h);
}

void	ft_put_str(t_long *m)
{
	int		i;
	int		x;
	char	*buff;
	char	*str;

	i = -1;
	x = 0;
	while (m->lom[0][++i])
	{
		mlx_put_image_to_window(m->p, m->m_w, m->header, x, 0);
		x += 50;
	}
	str = ft_itoa(m->c_m);
	buff = ft_strjoin("mouves :  ", str);
	mlx_string_put(m->p, m->m_w, 10, 5, 0xA7FC29, buff);
	free(buff);
	free (str);
}

static void	help_mouve_enemy(t_long *m)
{
	if (m->lom[m->i][m->j] == 'W')
	{
		if ((m->k < 5000) && m->lom[m->i][m->j - 1] == '0')
		{
			m->lom[m->i][m->j] = '0';
			m->lom[m->i][m->j - 1] = 'W';
		}
		else if (m->lom[m->i][m->j + 1] == '0')
		{
			m->lom[m->i][m->j] = '0';
			m->lom[m->i][++m->j] = 'W';
		}
	}
}

void	ft_mouve_enemy(t_long *m)
{
	m->i = -1;
	while (m->lom[++m->i] && !(m->k % 1000))
	{
		m->j = -1;
		while (m->lom[m->i][++m->j])
		{
			help_mouve_enemy(m);
		}
	}
	if (!(m->k % 1000))
		images(m);
	m->k++;
}

int	animation(t_long *m)
{
	static int		i;
	static int		j;

	ft_mouve_enemy(m);
	if (m->c_coin == 0 && i == 0)
	{
		i = 1;
		m->exit = mlx_xpm_file_to_image(m->p, "./img/Door_o.xpm", &m->w, &m->h);
		images(m);
	}
	if (m->k == 10000)
		m->k = 0;
	if (j == 1000)
	{
		m->coin = mlx_xpm_file_to_image(m->p, "./img/coin.xpm", &m->w, &m->h);
	}
	else if (j == 2000)
	{
		m->coin = mlx_xpm_file_to_image(m->p, "./img/coin_b.xpm", &m->w, &m->h);
		j = 0;
	}
	j++;
	return (1);
}
