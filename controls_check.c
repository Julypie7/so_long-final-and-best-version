/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:35:43 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/18 15:48:19 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	good_move(t_game *game, size_t i, size_t j)
{
	if (game->mat[j][i] == '0')
		change_pos(game, i, j);
	if (game->mat[j][i] == 'C')
	{
		change_pos(game, i, j);
		game->coins--;
	}
	if (game->mat[j][i] == 'E')
	{
		if (game->coins)
			change_pos(game, i, j);
		else
		{
			ft_printf("\nYou have won!\n");
			exit_game(game);
		}
	}
	return (1);
}

int	check_control(t_game *game, size_t i, size_t j)
{
	int	a;

	if (game->mat[j][i] == '1')
		return (0);
	a = good_move(game, i, j);
	if (!a)
		return (0);
	return (1);
}

void	ft_printexit(char *str, int ex)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0)
		ft_printf("%s\n", str);
	exit(ex);
}

void	mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, \
			(game->length * 40), (game->height * 40), "so_long");
	place_img_in_game(game);
	if (game->floor == NULL || game->wall == NULL \
			|| game->player == NULL || game->ex == NULL \
			|| game->collect == NULL)
		ft_exit("Error: images\n", 1, game, 2);
	add_graphics(game);
	mlx_key_hook(game->mlx_win, controls, game);
	mlx_hook(game->mlx_win, 17, (1L << 0), (void *)exit, 0);
	mlx_loop(game->mlx);
}

void	change_pos(t_game *game, size_t i, size_t j)
{
	game->mat[j][i] = 'P';
	i = game->p_x;
	j = game->p_y;
	game->mov++;
}
