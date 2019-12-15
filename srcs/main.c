/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:43:01 by mfrias            #+#    #+#             */
/*   Updated: 2019/08/24 12:14:22 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_all(t_filler *info)
{
	int	i;

	i = -1;
	while (++i < info->size.y)
		free(info->board[i]);
	free(info->board);
	i = -1;
	while (++i < info->size_piece.y)
		free(info->piece[i]);
	free(info->piece);
}

int		main(void)
{
	t_filler	*info;

	info = (t_filler *)ft_memalloc(sizeof(t_filler));
	info->player = get_player();
	info->dir = 0;
	while (1)
	{
		get(info);
		get_empty_lines(info);
		get_result(info);
		ft_printf("%d %d\n", info->place.y - info->empty.y,
				info->place.x - info->empty.x);
		free_all(info);
	}
	free(info);
	return (0);
}
