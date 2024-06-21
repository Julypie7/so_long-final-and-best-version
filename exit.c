/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:52:19 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/18 15:52:54 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	exit_game(t_game *game)
{
	if (game->mlx_win)
	{
		mlx_destroy_image(game->mlx, game->floor);
		mlx_destroy_image(game->mlx, game->wall);
		mlx_destroy_image(game->mlx, game->player);
		mlx_destroy_image(game->mlx, game->ex);
		mlx_destroy_image(game->mlx, game->collect);
		mlx_destroy_window(game->mlx, game->mlx_win);
	}
	free(game->mlx);
	f_free(game);
	free(game);
	exit(0);
}
