/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosnakam <kosnakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:23:52 by kosnakam          #+#    #+#             */
/*   Updated: 2024/04/19 16:04:32 by kosnakam         ###   ########.fr       */
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
