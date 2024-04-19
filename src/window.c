/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosnakam <kosnakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:10:57 by kosnakam          #+#    #+#             */
/*   Updated: 2024/04/19 16:06:10 by kosnakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_line_len(t_mlx *mlx, int fd)
{
	char	buffer[1];
	int		len;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	len = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			len++;
		else
			break ;
	}
	mlx->map_x = len;
	mlx->win_x = len * SIZE;
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
		ft_merror("開けんかった");
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		ft_merror("マップのパスが無効です");
	mlx->argv = argv[1];
	ft_line_len(mlx, fd);
	ft_count_lines(mlx, fd);
}
