/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:14:34 by ybouali           #+#    #+#             */
/*   Updated: 2022/02/07 03:58:19 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_long	*info;

	if (ac == 2)
	{
		info = (t_long *)malloc(sizeof(t_long));
		info->lom = ft_check_line_map(av[1]);
		ft_launch(info);
	}
}
