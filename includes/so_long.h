/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:59:47 by ybouali           #+#    #+#             */
/*   Updated: 2022/02/07 04:46:12 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// include libary
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_long
{
	void	*p;
	void	*m_w;
	void	*wall;
	void	*player;
	void	*monster;
	void	*exit;
	void	*back;
	void	*header;
	void	*coin;
	char	**lom;
	int		c_m;
	int		c_coin;
	int		w;
	int		h;
	int		e;
	int		i;
	int		j;
	int		p_y_player;
	int		p_x_player;
	int		k;
	int		width;
	int		height;
}	t_long;

void	ft_launch(t_long *info);
void	ft_check_name_map(char *map);
int		ft_check_first_last(char *line);
char	**ft_stock_table(char *name);
char	**ft_check_line_map(char *name_map);
void	ft_check_middle_lines(char **lines_of_map);
void	ft_free_table(char **table);
int		ft_get_length_of_map(char **table);
void	ft_err_exit(char *str, char **table, void *buff, t_long *m);
int		ft_strcmp(char *str1, char *str2, int len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);
char	*get_next_line(int fd);
int		ft_bufflen(char *buff);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
int		animation(t_long *m);
void	ft_stock_img(t_long *m);
int		mouves(t_long *m);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		event(int key, t_long *m);
void	images(t_long *m);
void	ft_put_str(t_long *m);

#endif
