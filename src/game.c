/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosnakam <kosnakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:21:49 by kosnakam          #+#    #+#             */
/*   Updated: 2024/04/19 16:02:35 by kosnakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clean_map(t_mlx *mlx)
{
	t_img	img;

	img.relative_path = "./img/0.xpm";
	img.mlx = *mlx;
	ft_put_img(img, mlx->play.player_point_x, mlx->play.player_point_y);
}

void	ft_get_c(t_mlx *mlx, int x, int y)
{
	t_img	img;

	img.relative_path = "./img/0.xpm";
	img.mlx = *mlx;
	ft_put_img(img, x, y);
	mlx->play.c_count++;
}

int	ft_move_check(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y / SIZE][x / SIZE] == '1')
	{
		ft_printf("そこは通れないよ！\n");
		return (0);
	}
	else if (mlx->map[y / SIZE][x / SIZE] == 'C')
	{
		mlx->map[y / SIZE][x / SIZE] = '0';
		ft_get_c(mlx, x, y);
		return (1);
	}
	else if (mlx->map[y / SIZE][x / SIZE] == 'E')
	{
		if (mlx->play.c_count == mlx->cflag)
			ft_error("おめ", mlx);
		else
		{
			ft_printf("アイテムを全部集めましょう\n");
			return (0);
		}
	}
	return (1);
}
