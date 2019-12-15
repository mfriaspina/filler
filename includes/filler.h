/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:30:44 by mfrias            #+#    #+#             */
/*   Updated: 2019/08/23 13:00:31 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_filler
{
	char		player;
	char		dir;
	char		**board;
	t_point		size;
	char		**piece;
	t_point		size_piece;
	t_point		place;
	t_point		empty;
	t_point		empty_br;
	int			ret;
}				t_filler;

void			get(t_filler *info);
void			free_all(t_filler *info);

char			get_player(void);
void			get_empty_lines(t_filler *info);

void			placeable(t_filler *info);
void			get_result(t_filler *info);

void			top(t_filler *info);
void			right(t_filler *info);
void			bottom(t_filler *info);
void			left(t_filler *info);

#endif
