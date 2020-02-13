/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:52:10 by tblancha          #+#    #+#             */
/*   Updated: 2020/02/11 04:39:42 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int
	search_char_in_tab(char **tab, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] == c)
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

static int
	bc_distance_min(t_placement *pos, t_piece *piece, t_map *map, int star)
{
	int	tmp_dis;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tmp_dis = map->nl + map->nc;
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			if (map->map[i][j] == pos->skin_en)
				if ((ft_abs(i - (pos->tmp_i + piece->piece[star][0]))
							+ ft_abs(j - (pos->tmp_j
									+ piece->piece[star][1]))) < tmp_dis)
					tmp_dis = ft_abs(i - (pos->tmp_i + piece->piece[star][0]))
						+ ft_abs(j - (pos->tmp_j + piece->piece[star][1]));
			j++;
		}
		i++;
		j = 0;
	}
	return (tmp_dis);
}

static void
	better_than_last(t_placement *pos, t_piece *piece, t_map *map)
{
	int	i;
	int	tmp_how_many;
	int	tmp_distance;

	tmp_how_many = 0;
	i = 0;
	while (i < piece->nb_star)
	{
		tmp_distance = bc_distance_min(pos, piece, map, i);
		if (tmp_distance == pos->distance_min)
			tmp_how_many++;
		if (tmp_distance < pos->distance_min
		|| (tmp_distance == pos->distance_min
			&& tmp_how_many > pos->how_many))
		{
			pos->x = pos->tmp_i;
			pos->y = pos->tmp_j;
			pos->how_many = tmp_how_many;
			pos->distance_min = tmp_distance;
		}
		i++;
	}
}

static int
	pos_check(t_placement *pos, t_piece *piece, t_map *map, t_player *player)
{
	int	i;
	int	superpos;

	i = 0;
	superpos = 0;
	if (pos->tmp_i + piece->nl > map->nl || pos->tmp_j + piece->nc > map->nc)
		return (0);
	while (i < piece->nb_star)
	{
		if (map->map[pos->tmp_i + piece->piece[i][0]][pos->tmp_j
				+ piece->piece[i][1]] == player->me1
				|| map->map[pos->tmp_i + piece->piece[i][0]][pos->tmp_j
				+ piece->piece[i][1]] == player->me2)
			superpos += 1;
		if (map->map[pos->tmp_i + piece->piece[i][0]][pos->tmp_j
				+ piece->piece[i][1]] == player->en1
		|| map->map[pos->tmp_i + piece->piece[i][0]][pos->tmp_j
		+ piece->piece[i][1]] == player->en2)
			return (0);
		i++;
	}
	if (superpos == 1)
		return (1);
	return (0);
}

void
	placement_piece(t_placement *pos, t_piece *piece, t_map *map,
			t_player *player)
{
	pos->skin_en = player->en1;
	if (search_char_in_tab(map->map, player->en2) == 1)
		pos->skin_en = player->en2;
	while (map->map[pos->tmp_i])
	{
		while (map->map[pos->tmp_i][pos->tmp_j])
		{
			if (pos_check(pos, piece, map, player) == 1)
				better_than_last(pos, piece, map);
			pos->tmp_j++;
		}
		pos->tmp_i++;
		pos->tmp_j = 0;
	}
}
