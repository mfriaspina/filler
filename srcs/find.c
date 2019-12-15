/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:37:15 by mfrias            #+#    #+#             */
/*   Updated: 2019/08/23 14:11:27 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	overlap(t_filler *info, t_point p, t_point sum, char c)
{
	char o;

	o = info->player;
	if (info->piece[p.y][p.x] == '*' && ft_orup(info->board[sum.y][sum.x], c))
	{
		info->ret = 0;
		return (0);
	}
	if (info->piece[p.y][p.x] == '*' && ft_orup(info->board[sum.y][sum.x], o))
	{
		if (info->ret == 1)
		{
			info->ret = 0;
			return (0);
		}
		info->ret = 1;
		return (1);
	}
	return (2);
}

void		placeable(t_filler *info)
{
	t_point	p;
	t_point	sum;
	char	c;

	p.y = info->empty.y - 1;
	c = info->player == 'o' ? 'x' : 'o';
	while (++p.y < info->size_piece.y - info->empty_br.y)
	{
		p.x = info->empty.x - 1;
		while (++p.x < info->size_piece.x - info->empty_br.x)
		{
			sum.x = p.x + info->place.x - info->empty.x;
			sum.y = p.y + info->place.y - info->empty.y;
			if ((sum.x >= info->size.x || sum.y >= info->size.y) &&
			info->piece[p.y][p.x] == '*')
			{
				info->ret = 0;
				return ;
			}
			if (!overlap(info, p, sum, c))
				return ;
		}
	}
}

void		get_result(t_filler *info)
{
	info->ret = 0;
	info->dir = !info->dir;
	if (info->dir == 2)
		top(info);
	else if (info->dir == 1)
		right(info);
	else if (info->dir == 2)
		bottom(info);
	else if (info->dir == 0)
		left(info);
}
