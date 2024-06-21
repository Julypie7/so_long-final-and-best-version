/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:23:13 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/18 16:08:41 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 

# include "../gnl/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "so_l_utils.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <fcntl.h>

int		main(int argc, char **argv);
int		check_ber(char *str);
void	init_map(t_game *game);
int		open_map(char *path);
int		validate_map(t_game *game, char *path);
void	check_rectang(t_game *game, size_t *first_length, char *new_first);
void	parsing(t_game *game);
void	map_closed(t_game *game, size_t i, size_t j);
void	f_free(t_game *game);
void	ff_free(char	**game);
void	one_exit(t_game *game, size_t i, size_t j);
void	one_col(t_game *game, size_t i, size_t j);
void	find_p(t_game *game, size_t i, size_t j);
void	otr_letr(t_game *game, size_t i, size_t j);
void	flood_fill(t_game *copy, size_t x, size_t y);
void	check(t_game *game, t_game *copy);
int		key_hook(int keycode, t_game *vars);
void	place_img_in_game(t_game *game);
void	put_player(t_game *game, size_t height, size_t length);
void	put_coin(t_game *game, size_t h, size_t l);
void	add_graphics(t_game *game);
t_game	*init(void);
char	*ft_strcpy(char *dst, const char *src);
int		add_line_map(t_game *game, char *line);
void	add_new_first(t_game *game, char *line);
t_game	*init_copy(t_game *game);
t_game	*copy_map(t_game *game, t_game *copy);
void	ft_exit(char *str, int ex, t_game *game, int g);
int		controls(int command, t_game *game);
int		exit_game(t_game *game);
void	copypx(t_game *copy, t_game *game);
void	image_to_window(t_game *game, size_t height, size_t length);
int		check_control(t_game *game, size_t i, size_t j);
int		good_move(t_game *game, size_t i, size_t j);
void	*my_realloc(void *ptr, size_t new_size);
void	ft_printexit(char *str, int ex);
void	mlx(t_game *game);
void	change_pos(t_game *game, size_t i, size_t j);

#endif
