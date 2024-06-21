/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_l_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:41:44 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/18 13:05:19 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_L_UTILS_H
# define SO_L_UTILS_H

typedef struct s_mem_block
{
	size_t	size;
	char	data[];
}			t_mem_block;	

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	void		*floor;
	void		*wall;
	void		*player;
	void		*ex;
	void		*collect;

	size_t		p_x;
	size_t		p_y;
	size_t		e_x;
	size_t		e_y;
	char		**mat;
	size_t		mov;
	size_t		x;
	size_t		y;
	size_t		height;
	size_t		length;
	size_t		coins;
	size_t		ncoins;
	size_t		exit;
	size_t		nexit;
	size_t		collectable;
}			t_game;

#endif
