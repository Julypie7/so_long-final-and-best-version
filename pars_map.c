/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:51:01 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/18 13:32:00 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	map_closed(t_game *game, size_t i, size_t j)
{
	while (j < game->length)
	{
		if (game->mat[0][j] != '1' || game->mat[game->height - 1][j] != '1')
			ft_exit("Error - wall is not closed", 1, game, 3);
		j++;
	}
	while (i < game->height)
	{
		if (game->mat[i][0] != '1' || game->mat[i][game->length - 1] != '1')
			ft_exit("Error - wall is not closed", 1, game, 3);
		i++;
	}
}

void	one_exit(t_game *game, size_t i, size_t j)
{
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->length)
		{
			if (game->mat[i][j] == 'E')
			{
				game->e_x = j;
				game->e_y = i;
				game->exit++;
			}
			j++;
		}
		i++;
	}
	if (game->exit != 1)
		ft_exit("Error, exit", 1, game, 3);
}

void	find_p(t_game *game, size_t i, size_t x)
{
	int	p;

	i = 0;
	p = 0;
	while (i < game->height)
	{
		x = 0;
		while (x < game->length)
		{
			if (game->mat[i][x] == 'P')
			{
				game->p_y = i;
				game->p_x = x;
				p++;
			}
			x++;
		}
		i++;
	}
	if (p != 1)
		ft_exit("Error, Player", 1, game, 3);
}

void	one_col(t_game *game, size_t i, size_t j)
{
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->length)
		{
			if (game->mat[i][j] == 'C')
				game->coins++;
			j++;
		}
		i++;
	}
	if (game->coins < 1)
		ft_exit("Less than one coin", 1, game, 3);
}

void	otr_letr(t_game *game, size_t i, size_t j)
{
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->length)
		{
			if (game->mat[i][j] != '1' && game->mat[i][j] != 'C' \
					&& game->mat[i][j] != 'P' && game->mat[i][j] != 'E' \
					&& game->mat[i][j] != '0')
				ft_exit("Invalid map, unrecognized letters", 1, game, 3);
			j++;
		}
		i++;
	}
}
