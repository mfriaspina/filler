/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:14:20 by mfrias            #+#    #+#             */
/*   Updated: 2019/08/24 12:34:24 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		get_player(void)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "mfrias") && ft_strstr(line, "p1"))
		{
			ft_strdel(&line);
			return ('o');
		}
		else if (ft_strstr(line, "mfrias") && ft_strstr(line, "p2"))
		{
			ft_strdel(&line);
			return ('x');
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return ('o');
}

static void	get_empty_br(t_filler *info)
{
	t_point	p;

	p.y = info->size_piece.y;
	while (--p.y >= 0)
		if (ft_strchr(info->piece[p.y], '*'))
		{
			info->empty_br.y = info->size_piece.y - p.y - 1;
			break ;
		}
	p.x = info->size_piece.x;
	while (--p.x >= 0)
	{
		p.y = -1;
		while (++p.y < info->size_piece.y)
			if (info->piece[p.y][p.x] == '*')
			{
				info->empty_br.x = info->size_piece.x - p.x - 1;
				return ;
			}
	}
}

void		get_empty_lines(t_filler *info)
{
	t_point	p;

	p.y = -1;
	while (++p.y < info->size_piece.y)
		if (ft_strchr(info->piece[p.y], '*'))
		{
			info->empty.y = p.y;
			break ;
		}
	p.x = -1;
	while (++p.x < info->size_piece.x)
	{
		p.y = -1;
		while (++p.y < info->size_piece.y)
			if (info->piece[p.y][p.x] == '*')
			{
				info->empty.x = p.x;
				get_empty_br(info);
				return ;
			}
	}
	get_empty_br(info);
}
