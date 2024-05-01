/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosnakam <kosnakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:08:28 by kosnakam          #+#    #+#             */
/*   Updated: 2024/05/01 11:46:50 by kosnakam         ###   ########.fr       */
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
	while (mlx->map_c[i])
		free(mlx->map_c[i++]);
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
				ft_error("Error\n最後の行を改行していないか、壁に穴が空いています", mlx);
			ft_put_piece(mlx, img, i, j);
			j++;
		}
		i++;
	}
	if (mlx->pflag != 1)
		ft_error("Error\nキャラクターは一体だけです", mlx);
	if (mlx->cflag == 0)
		ft_error("Error\nマップにアイテムが一つも含まれていません", mlx);
	if (mlx->eflag != 1)
		ft_error("Error\n出口は一つだけです", mlx);
}

void	ft_clear_check(t_mlx *mlx, int y, int x)
{
	if (mlx->map_c[y][x] == '1')
		;
	else if (mlx->map_c[y][x] == 'E')
		mlx->map_c[y][x] = '1';
	else
	{
		mlx->map_c[y][x] = '1';
		ft_clear_check(mlx, y + 1, x);
		ft_clear_check(mlx, y - 1, x);
		ft_clear_check(mlx, y, x + 1);
		ft_clear_check(mlx, y, x - 1);
	}
}

void	ft_map_check2(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->map_y)
	{
		x = 0;
		if (ft_strlen(mlx->map[y]) - 1 != (size_t)(mlx->map_x)
			&& y != (mlx->map_y))
			ft_error("Error\nマップは四角でなくてはなりません", mlx);
		while (x < mlx->map_x)
		{
			if (!(mlx->map_c[y][x] == '0' || mlx->map_c[y][x] == '1'))
				ft_error("Error\nクリア出来ないマップです", mlx);
			x++;
		}
		y++;
	}
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
	mlx->map_c = (char **)malloc(sizeof(char *) * OPEN_MAX);
	if (!mlx->map || !mlx->map_c)
		ft_merror("Error\nマロックに失敗しました泣");
	if (mlx->map[mlx->map_y] && mlx->map[mlx->map_y][0] != '\0')
		ft_error("Error\nマップに誤りがあります", mlx);
	while (y < mlx->map_y)
	{
		mlx->map[y] = get_next_line(fd);
		mlx->map_c[y] = ft_strdup(mlx->map[y]);
		if (!mlx->map[y] || !mlx->map_c[y])
			ft_merror("Error\nマロックに失敗しました泣");
		y++;
	}
	ft_map_check(mlx, &img);
	ft_clear_check(mlx, mlx->play.player_point_y / SIZE,
		mlx->play.player_point_x / SIZE);
	ft_map_check2(mlx);
}
