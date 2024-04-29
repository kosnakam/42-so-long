/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosnakam <kosnakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:10:57 by kosnakam          #+#    #+#             */
/*   Updated: 2024/04/29 18:33:16 by kosnakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_line_count(t_mlx *mlx, int fd)
{
	char	buffer[1];
	int		count;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	count = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			count++;
		else
			break ;
	}
	mlx->map_x = count;
	if (count >= 54)
		ft_merror("Error\n無効なマップです");
	mlx->win_x = count * SIZE;
}

void	ft_count_lines(t_mlx *mlx, int fd)
{
	int		count;
	char	buffer[1];
	int		bytes;

	buffer[0] = '\0';
	count = 1;
	while (1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes < 1)
			break ;
		if (buffer[0] == '\n')
			count++;
	}
	mlx->map_y = count;
	if (count >= 30)
		ft_merror("Error\n無効なマップです");
	mlx->win_y = count * SIZE;
}

int	ft_close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	ft_error("よく頑張った", mlx);
	exit(0);
}

void	ft_window_size(t_mlx *mlx, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_merror("Error\n開けんかった");
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		ft_merror("Error\nマップのパスが無効です");
	mlx->argv = argv[1];
	ft_line_count(mlx, fd);
	ft_count_lines(mlx, fd);
}
