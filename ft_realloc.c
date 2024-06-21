/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:40:49 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/18 15:39:13 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	*my_realloc(void *ptr, size_t new_size)
{
	void	**from_copy;
	void	**buff_dir_mem;
	int		len;
	int		i;

	(void)new_size;
	len = 0;
	from_copy = (void **)ptr;
	while (ptr && from_copy[len])
		len += 1;
	buff_dir_mem = malloc(sizeof(void *) * (len + 2));
	if (!buff_dir_mem)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buff_dir_mem[i] = from_copy[i];
		i++;
	}
	buff_dir_mem[i] = NULL;
	buff_dir_mem[i + 1] = NULL;
	free(ptr);
	return ((void *)buff_dir_mem);
}
