/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:54:44 by mfrias            #+#    #+#             */
/*   Updated: 2019/08/21 12:36:41 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	make_board(char *line, t_filler *info)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (ft_isdigit(line[i]))
		{
			info->size.y = ft_atoi(&line[i]);
			while (line[i] != ' ')
				i++;
			info->size.x = ft_atoi(&line[++i]);
			break ;
		}
	}
	ft_strdel(&line);
	info->board = (char **)ft_memalloc(sizeof(char *) * info->size.y);
	return (1);
}

static int	make_piece(char *line, t_filler *info)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (ft_isdigit(line[i]))
		{
			info->size_piece.y = ft_atoi(&line[i]);
			while (line[i] != ' ')
				i++;
			info->size_piece.x = ft_atoi(&line[++i]);
			break ;
		}
	}
	ft_strdel(&line);
	info->piece = (char **)ft_memalloc(sizeof(char *) * info->size_piece.y);
	return (2);
}

static int	get_board(char *line, t_filler *info)
{
	int	i;

	i = -1;
	ft_strdel(&line);
	while (++i < info->size.y)
	{
		get_next_line(0, &line);
		info->board[i] = ft_strdup(&line[4]);
		ft_strdel(&line);
	}
	return (0);
}

static int	get_piece(char *line, t_filler *info)
{
	int	i;

	i = 0;
	info->piece[0] = ft_strdup(line);
	ft_strdel(&line);
	while (++i < info->size_piece.y)
	{
		get_next_line(0, &line);
		info->piece[i] = ft_strdup(line);
		ft_strdel(&line);
	}
	return (3);
}

void		get(t_filler *info)
{
	char		*line;
	int			grid;

	grid = 0;
	while (grid != 3)
	{
		get_next_line(0, &line);
		if (grid == 1)
			grid = get_board(line, info);
		else if (grid == 2)
			grid = get_piece(line, info);
		else if (ft_strstr(line, "Plateau"))
			grid = make_board(line, info);
		else if (ft_strstr(line, "Piece"))
			grid = make_piece(line, info);
		else
			ft_strdel(&line);
	}
}
