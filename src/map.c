/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosnakam <kosnakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:08:28 by kosnakam          #+#    #+#             */
/*   Updated: 2024/04/22 19:46:40 by kosnakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close_map(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map[i])
		free(mlx->map[i++]);
	free(mlx->map);
}

int	ft_can_clear(t_mlx *mlx, int y, int x)
{
	if (mlx->map[y + 1][x] == '1' && mlx->map[y - 1][x] == '1'
		&& mlx->map[y][x + 1] == '1' && mlx->map[y][x - 1] == '1')
		return (0);
	return (1);
}

void	ft_put_piece(t_mlx *mlx, t_img *img, int y, int x)
{
	if (mlx->map[y][x] == '1')
		img->relative_path = "./img/1.xpm";
	else if (mlx->map[y][x] == 'P' && ft_can_clear(mlx, y, x))
	{
		mlx->play.player_point_x = x * SIZE;
		mlx->play.player_point_y = y * SIZE;
		mlx->pflag++;
		img->relative_path = "./img/p.xpm";
	}
	else if (mlx->map[y][x] == 'C' && ft_can_clear(mlx, y, x))
	{
		mlx->cflag++;
		img->relative_path = "./img/c.xpm";
	}
	else if (mlx->map[y][x] == 'E' && ft_can_clear(mlx, y, x))
	{
		mlx->eflag++;
		img->relative_path = "./img/e.xpm";
	}
	else if (mlx->map[y][x] == '0')
		;
	else
		ft_error("無効なマップです", mlx);
	ft_put_img(*img, x * SIZE, y * SIZE);
}

void	ft_map_check(t_mlx *mlx, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map_y)
	{
		j = 0;
		while (j < mlx->map_x)
		{
			img->relative_path = "./img/0.xpm";
			ft_put_img(*img, j * SIZE, i * SIZE);
			if ((i == 0 || j == 0 || j == mlx->map_x - 1 || i == mlx->map_y - 1)
				&& mlx->map[i][j] != '1')
				ft_error("マップは壁で囲まれている必要があります", mlx);
			ft_put_piece(mlx, img, i, j);
			j++;
		}
		i++;
	}
	if (mlx->pflag != 1)
		ft_error("キャラクターは１体だけです", mlx);
	if (mlx->cflag == 0)
		ft_error("マップにアイテムが一つも含まれていません", mlx);
	if (mlx->eflag == 0)
		ft_error("マップに出口がありません", mlx);
}

void	ft_create_map(t_mlx *mlx)
{
	t_img	img;
	int		y;
	int		fd;

	img.mlx = *mlx;
	y = 0;
	fd = open(mlx->argv, O_RDONLY);
	mlx->map = (char **)malloc(sizeof(char *) * OPEN_MAX);
	if (!mlx->map)
		ft_merror("マロックに失敗しました泣");
	if (mlx->map[mlx->map_y] && mlx->map[mlx->map_y][0] != '\0')
		ft_error("マップに誤りがあります", mlx);
	while (y < mlx->map_y)
	{
		mlx->map[y] = get_next_line(fd);
		if (!mlx->map[y])
			ft_merror("マロックに失敗しました泣");
		if (ft_strlen(mlx->map[y]) - 1 != (size_t)(mlx->map_x)
			&& y != (mlx->map_y))
			ft_error("マップは四角でなくてはなりません", mlx);
		y++;
	}
	ft_map_check(mlx, &img);
}
