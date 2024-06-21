/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:10:04 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/18 16:04:11 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	mov_w(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = game->p_x;
	j = game->p_y;
	j--;
	a = check_control(game, i, j);
	if (!a)
		return (0);
	if (game->e_x == i && game->e_y == j + 1)
		game->mat[j + 1][i] = 'E';
	else
		game->mat[j + 1][i] = '0';
	ft_printf("Movements %i\n Coins left %i\n", game->mov, game->coins);
	return (1);
}

static int	mov_s(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = game->p_x;
	j = game->p_y;
	j++;
	a = check_control(game, i, j);
	if (!a)
		return (0);
	if (game->e_x == i && game->e_y == j - 1)
		game->mat[j - 1][i] = 'E';
	else
		game->mat[j - 1][i] = '0';
	ft_printf("Movements %i\n Coins left %i\n", game->mov, game->coins);
	return (1);
}

static int	mov_a(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = game->p_x;
	j = game->p_y;
	i--;
	a = check_control(game, i, j);
	if (!a)
		return (0);
	if (game->e_x == i + 1 && game->e_y == j)
		game->mat[j][i + 1] = 'E';
	else
		game->mat[j][i + 1] = '0';
	ft_printf("Movements %i\n Coins left %i\n", game->mov, game->coins);
	return (1);
}

static int	mov_d(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = game->p_x;
	j = game->p_y;
	i++;
	a = check_control(game, i, j);
	if (!a)
		return (0);
	if (game->e_x == i - 1 && game->e_y == j)
		game->mat[j][i - 1] = 'E';
	else
		game->mat[j][i - 1] = '0';
	ft_printf("Movements %i\n Coins left %i\n", game->mov, game->coins);
	return (1);
}

int	controls(int command, t_game *game)
{
	int	i;

	i = 0;
	if (command == 119)
		i = mov_w(game);
	if (command == 115)
		i = mov_s(game);
	if (command == 97)
		i = mov_a(game);
	if (command == 100)
		i = mov_d(game);
	if (command == 65307)
		i = exit_game(game);
	if (i)
		add_graphics(game);
	return (1);
}
