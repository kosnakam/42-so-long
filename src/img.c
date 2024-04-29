/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosnakam <kosnakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:23:52 by kosnakam          #+#    #+#             */
/*   Updated: 2024/04/29 18:01:55 by kosnakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_put_img(t_img img, int x, int y)
{
	img.img = mlx_xpm_file_to_image(img.mlx.mlx,
			img.relative_path, &img.img_width, &img.img_height);
	mlx_put_image_to_window(img.mlx.mlx, img.mlx.mlx_win, img.img, x, y);
	return (img.img);
}

void	ft_put_piece(t_mlx *mlx, t_img *img, int y, int x)
{
	if (mlx->map[y][x] == '1')
		img->relative_path = "./img/1.xpm";
	else if (mlx->map[y][x] == 'P')
	{
		mlx->play.player_point_x = x * SIZE;
		mlx->play.player_point_y = y * SIZE;
		mlx->pflag++;
		img->relative_path = "./img/p.xpm";
	}
	else if (mlx->map[y][x] == 'C')
	{
		mlx->cflag++;
		img->relative_path = "./img/c.xpm";
	}
	else if (mlx->map[y][x] == 'E')
	{
		mlx->eflag++;
		img->relative_path = "./img/e.xpm";
	}
	else if (mlx->map[y][x] == '0')
		;
	else
		ft_error("Error\n無効なマップです", mlx);
	ft_put_img(*img, x * SIZE, y * SIZE);
}
