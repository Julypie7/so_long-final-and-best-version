/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:49:00 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/18 16:56:02 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		win_width;
	int		win_height;

	if (argc != 2)
	{
		ft_printf("Error, wrong number of arg");
		exit(1);
	}
	if (argc == 2 && (check_ber(argv[1]) == 1))
	{
		game = init();
		validate_map(game, argv[1]);
		parsing(game);
		win_width = game->length * 40;
		win_height = game->height * 40;
		if (win_height >= 1080 || win_width >= 1920)
			ft_exit("Error: Map is too large\n", 1, game, 2);
		mlx(game);
	}
	return (0);
}

void	parsing(t_game *game)
{
	t_game	*copy;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	otr_letr(game, i, j);
	map_closed(game, i, j);
	one_exit(game, i, j);
	find_p(game, i, j);
	one_col(game, i, j);
	copy = init_copy(game);
	flood_fill(copy_map(copy, game), copy->p_x, copy->p_y);
	check(game, copy);
}

void	ft_exit(char *str, int ex, t_game *game, int g)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0)
		ft_printf("%s\n", str);
	if (g == 1)
	{
		f_free(game);
		free(game);
	}
	if (g == 2)
	{
		free(game->mlx);
		f_free(game);
		free(game);
	}
	if (g == 3)
	{
		f_free(game);
		free(game);
	}
	exit(ex);
}

void	f_free(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->height)
	{
		free(game->mat[i]);
		i++;
	}
	free(game->mat);
}

int	check_ber(char *str)
{
	size_t	i;

	i = ft_strlen(str);
	i -= 4;
	if (str[i] != '.')
		ft_printexit("Incorrect name", 1);
	i++;
	if (str[i] != 'b')
		ft_printexit("Incorrect name", 1);
	i++;
	if (str[i] != 'e')
		ft_printexit("Incorrect name", 1);
	i++;
	if (str[i] != 'r')
		ft_printexit("Incorrect name", 1);
	return (1);
}
