/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:08:36 by ineimatu          #+#    #+#             */
/*   Updated: 2024/05/30 16:25:20 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	place_img_in_game(t_game *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx, \
			"textures/Floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx, \
			"textures/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx, \
			"textures/Mouse.xpm", &i, &j);
	game->ex = mlx_xpm_file_to_image(game->mlx, \
			"textures/exit.xpm", &i, &j);
	game->collect = mlx_xpm_file_to_image(game->mlx, \
			"textures/coins.xpm", &i, &j);
}

void	put_player(t_game *game, size_t height, size_t length)
{
	game->p_x = length;
	game->p_y = height;
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->player, length * 40, height * 40);
}

void	put_coin(t_game *game, size_t h, size_t l)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->collect, l * 40, h * 40);
	game->collectable++;
}

void	image_to_window(t_game *game, size_t height, size_t length)
{
	if (game->mat[height][length] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->wall, length * 40, height * 40);
	if (game->mat[height][length] == 'C')
		put_coin(game, height, length);
	if (game->mat[height][length] == 'P')
		put_player(game, height, length);
	if (game->mat[height][length] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->ex, length * 40, height * 40);
	if (game->mat[height][length] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->floor, length * 40, height * 40);
}

void	add_graphics(t_game *game)
{
	size_t	height;
	size_t	length;

	game->collectable = 0;
	height = 0;
	while (height < game->height)
	{
		length = 0;
		while (game->mat[height][length])
		{
			image_to_window(game, height, length);
			length++;
		}
		height++;
	}
}
