/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:18:35 by mfrias            #+#    #+#             */
/*   Updated: 2019/08/24 11:49:39 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	top(t_filler *info)
{
	info->place.y = -1;
	while (++info->place.y < info->size.y)
	{
		info->place.x = -1;
		while (++info->place.x < info->size.x)
		{
			placeable(info);
			if (info->ret == 1)
				return ;
		}
	}
	ft_printf("0 0\n");
	free_all(info);
	free(info);
	exit(1);
}

void	right(t_filler *info)
{
	info->place.x = info->size.x;
	while (--info->place.x >= 0)
	{
		info->place.y = -1;
		while (++info->place.y < info->size.y)
		{
			placeable(info);
			if (info->ret == 1)
				return ;
		}
	}
	ft_printf("0 0\n");
	free_all(info);
	free(info);
	exit(1);
}

void	left(t_filler *info)
{
	info->place.x = -1;
	while (++info->place.x < info->size.x)
	{
		info->place.y = info->size.y;
		while (--info->place.y >= 0)
		{
			placeable(info);
			if (info->ret == 1)
				return ;
		}
	}
	ft_printf("0 0\n");
	free_all(info);
	free(info);
	exit(1);
}

void	bottom(t_filler *info)
{
	info->place.y = info->size.y;
	while (--info->place.y >= 0)
	{
		info->place.x = info->size.x;
		while (--info->place.x >= 0)
		{
			placeable(info);
			if (info->ret == 1)
				return ;
		}
	}
	ft_printf("0 0\n");
	free_all(info);
	free(info);
	exit(1);
}
