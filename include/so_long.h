/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosnakam <kosnakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:41:50 by kosnakam          #+#    #+#             */
/*   Updated: 2024/09/25 14:38:28 by kosnakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZE	48
# define ESC	53
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"

typedef struct s_play
{
	int	player_point_x;
	int	player_point_y;
	int	c_count;
	int	m_count;
}	t_play;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*argv;
	char	**map;
	char	**map_c;
	int		map_x;
	int		map_y;
	int		win_x;
	int		win_y;
	int		pflag;
	int		cflag;
	int		eflag;
	t_play	play;
}	t_mlx;

typedef struct s_img
{
	t_mlx	mlx;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
}	t_img;

void	ft_error(char *msg, t_mlx *mlx);
void	ft_merror(char *msg);
void	ft_window_size(t_mlx *mlx, char **argv);
void	ft_create_map(t_mlx *mlx);
void	*ft_put_img(t_img img, int x, int y);
int		ft_close_window(t_mlx *mlx);
void	ft_move_up(t_mlx *mlx);
void	ft_move_down(t_mlx *mlx);
void	ft_move_left(t_mlx *mlx);
void	ft_move_right(t_mlx *mlx);
int		ft_move_check(t_mlx *mlx, int x, int y);
void	ft_clean_map(t_mlx *mlx);
void	ft_put_piece(t_mlx *mlx, t_img *img, int y, int x);

#endif