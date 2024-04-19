/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosnakam <kosnakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:02:10 by kosnakam          #+#    #+#             */
/*   Updated: 2024/04/19 16:12:40 by kosnakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_mlx *mlx)
{
	t_img	img;
	int		x;
	int		y;

	img.relative_path = "./img/p.xpm";
	img.mlx = *mlx;
	x = mlx->play.player_point_x;
	y = mlx->play.player_point_y - SIZE;
	if (ft_move_check(mlx, x, y) == 1)
	{
		mlx->play.m_count++;
		ft_printf("%d回動いた\n", mlx->play.m_count);
		ft_clean_map(mlx);
		mlx->play.player_point_y -= SIZE;
		ft_put_img(img, mlx->play.player_point_x, mlx->play.player_point_y);
	}
}

void	ft_move_down(t_mlx *mlx)
{
	t_img	img;
	int		x;
	int		y;

	img.relative_path = "./img/p.xpm";
	img.mlx = *mlx;
	x = mlx->play.player_point_x;
	y = mlx->play.player_point_y + SIZE;
	if (ft_move_check(mlx, x, y) == 1)
	{
		mlx->play.m_count++;
		ft_printf("%d回動いた\n", mlx->play.m_count);
		ft_clean_map(mlx);
		mlx->play.player_point_y += SIZE;
		ft_put_img(img, mlx->play.player_point_x, mlx->play.player_point_y);
	}
}

void	ft_move_left(t_mlx *mlx)
{
	t_img	img;
	int		x;
	int		y;

	img.relative_path = "./img/p.xpm";
	img.mlx = *mlx;
	x = mlx->play.player_point_x - SIZE;
	y = mlx->play.player_point_y;
	if (ft_move_check(mlx, x, y) == 1)
	{
		mlx->play.m_count++;
		ft_printf("%d回動いた\n", mlx->play.m_count);
		ft_clean_map(mlx);
		mlx->play.player_point_x -= SIZE;
		ft_put_img(img, mlx->play.player_point_x, mlx->play.player_point_y);
	}
}

void	ft_move_right(t_mlx *mlx)
{
	t_img	img;
	int		x;
	int		y;

	img.relative_path = "./img/p.xpm";
	img.mlx = *mlx;
	x = mlx->play.player_point_x + SIZE;
	y = mlx->play.player_point_y;
	if (ft_move_check(mlx, x, y) == 1)
	{
		mlx->play.m_count++;
		ft_printf("%d回動いた\n", mlx->play.m_count);
		ft_clean_map(mlx);
		mlx->play.player_point_x += SIZE;
		ft_put_img(img, mlx->play.player_point_x, mlx->play.player_point_y);
	}
}
