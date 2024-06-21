/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:51:41 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/18 17:00:16 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	flood_fill(t_game *copy, size_t x, size_t y)
{
	if (x < 0 || x >= copy->length || y < 0 || y >= copy->height || \
			copy->mat[y][x] == '1' || copy->mat[y][x] == 'F')
		return ;
	if (copy->mat[y][x] == 'E')
		copy->nexit++;
	if (copy->mat[y][x] == 'C')
		copy->ncoins++;
	copy->mat[y][x] = 'F';
	flood_fill(copy, x + 1, y);
	flood_fill(copy, x - 1, y);
	flood_fill(copy, x, y + 1);
	flood_fill(copy, x, y - 1);
}

void	check(t_game *game, t_game *copy)
{
	if (game->coins != copy->ncoins || game->exit != copy->nexit)
		ft_exit("Error, Ureachable c/e", 1, game, 1);
	f_free(copy);
	free(copy);
}

void	add_new_first(t_game *game, char *line)
{
	if (!add_line_map(game, line))
	{
		free(line);
		ft_exit("Error to add line to the map", 1, game, 1);
	}
	free(line);
}

t_game	*init_copy(t_game *game)
{
	t_game	*copy;

	copy = malloc(sizeof(t_game));
	if (!copy)
		return (NULL);
	copy->p_x = game->p_x;
	copy->p_y = game->p_y;
	copy->length = game->length;
	copy->height = game->height;
	copy->ncoins = 0;
	copy->nexit = 0;
	copy->mat = malloc(sizeof(char *) * copy->height);
	if (copy->mat == NULL)
	{
		free(copy);
		exit(1);
	}
	return (copy);
}

t_game	*copy_map(t_game *copy, t_game *game)
{
	size_t		i;

	i = 0;
	while (i < copy->height)
	{
		copy->mat[i] = malloc(sizeof(char) * (copy->length + 1));
		if (copy->mat[i] == NULL)
		{
			free(copy->mat);
			free(copy);
			exit(1);
		}
		ft_strcpy(copy->mat[i], game->mat[i]);
		i++;
	}
	return (copy);
}
