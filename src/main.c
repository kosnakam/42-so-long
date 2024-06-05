/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosnakam <kosnakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:06:01 by kosnakam          #+#    #+#             */
/*   Updated: 2024/06/05 17:09:04 by kosnakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

__attribute__((destructor))
void	destructor(void)
{
	system("leaks -q so_long 1>&2");
}

void	ft_error(char *msg, t_mlx *mlx)
{
	ft_printf("%s\n", msg);
	exit(0);
}

void	ft_merror(char *msg)
{
	ft_printf("%s\n", msg);
	exit(0);
}

int	key_check(int key_code, t_mlx *mlx)
{
	if (key_code == ESC)
		ft_error("よく頑張った", mlx);
	if (key_code == UP)
		ft_move_up(mlx);
	if (key_code == DOWN)
		ft_move_down(mlx);
	if (key_code == LEFT)
		ft_move_left(mlx);
	if (key_code == RIGHT)
		ft_move_right(mlx);
	return (0);
}

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->pflag = 0;
	mlx->cflag = 0;
	mlx->eflag = 0;
	mlx->play.player_point_x = 0;
	mlx->play.player_point_y = 0;
	mlx->play.c_count = 0;
	mlx->play.m_count = 0;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		ft_merror("Error\n引数に正しいマップのパスを入力してください");
	ft_window_size(&mlx, argv);
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, mlx.win_x, mlx.win_y, "game");
	ft_init_mlx(&mlx);
	ft_create_map(&mlx);
	mlx_hook(mlx.mlx_win, 17, 1L << 2, ft_close_window, &mlx);
	mlx_key_hook(mlx.mlx_win, key_check, &mlx);
	mlx_loop(mlx.mlx);
}
