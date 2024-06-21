/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:21:19 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/18 16:58:29 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mat = NULL;
	game->height = 0;
	game->length = 0;
	game->mov = 0;
	game->e_x = 0;
	game->e_y = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->coins = 0;
	game->exit = 0;
	game->collectable = 0;
	return (game);
}

int	add_line_map(t_game *game, char *line)
{
	size_t	line_len;
	char	**new_grid;

	line_len = ft_strlen(line);
	if (game->height == 0)
		game->length = line_len;
	new_grid = my_realloc(game->mat, (game->height + 1) * sizeof(char *));
	if (new_grid == NULL)
		return (0);
	game->mat = new_grid;
	game->mat[game->height] = malloc(line_len + 1);
	if (game->mat[game->height] == NULL)
		return (0);
	ft_strcpy(game->mat[game->height], line);
	game->height++;
	return (1);
}

int	validate_map(t_game *game, char *path)
{
	char	*new_first;
	int		fd;
	size_t	first_length;

	new_first = NULL;
	first_length = 0;
	fd = open_map(path);
	while (1)
	{
		new_first = get_next_line(fd);
		if (!new_first)
			break ;	
		check_rectang(game, &first_length, new_first);
		add_new_first(game, new_first);
	}
	return (0);
}

int	open_map(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{	
		ft_printf("fd < 0");
		exit(1);
	}
	return (fd);
}

void	check_rectang(t_game *game, size_t *first_length, char *new_first)
{
	if (*first_length == 0)
		*first_length = ft_strlen(new_first);
	else if (ft_strlen(new_first) != *first_length)
	{
		if (game->mat)
			f_free(game);
		free(game);
		free(new_first);
		ft_printf("map is not rectangular\n");
		exit(1);
	}
}
