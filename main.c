/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 02:22:49 by tblancha          #+#    #+#             */
/*   Updated: 2020/02/12 06:26:25 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void
	ini_pos(t_placement *pos, int distance_max)
{
	pos->tmp_i = 0;
	pos->tmp_j = 0;
	pos->x = -1000;
	pos->y = -1000;
	pos->distance_min = distance_max;
	pos->how_many = 0;
}

void
	free_all(t_map *map, t_piece *piece)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (i < map->nl && map->map[i][0])
		{
			ft_strdel(&map->map[i]);
			i++;
		}
		ft_strdel(&map->map[i]);
		free(map->map);
		map->map = NULL;
	}
	i = 0;
	if (piece->piece)
	{
		while (/*i < piece->nb_star && */piece->piece[i] != NULL)
		{
			free(piece->piece[i]);
			piece->piece[i] = NULL;
			i++;
		}
		free(piece->piece[i]);
		free(piece->piece);
		piece->piece = NULL;
	}
}

int
	main(void)
{
	t_player			player;
	t_map				map_info;
	t_piece				piece;
	t_placement			pos;

	while (1)
	{
		ini_map(&map_info);
		if (!refonte(&player, &map_info, &piece))
			return (0);
		ini_pos(&pos, map_info.nl + map_info.nc);
		placement_piece(&pos, &piece, &map_info, &player);
		free_all(&map_info, &piece);
		if (pos.distance_min == map_info.nl + map_info.nc)
		{
			ft_printf("0 0\n");
			return (0);
		}
		ft_printf("%d %d\n", pos.x - piece.ref_nl, pos.y - piece.ref_nc);
	}
	return (0);
}