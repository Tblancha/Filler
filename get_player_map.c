/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:51:54 by tblancha          #+#    #+#             */
/*   Updated: 2020/02/12 03:09:55 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void
	ini_player(t_player *player, char me, char en)
{
	player->me1 = me;
	player->me2 = me + 32;
	player->en1 = en;
	player->en2 = en + 32;
}

void
	ini_map(t_map *map_info)
{
	map_info->nc = 0;
	map_info->nl = 0;
	map_info->map = NULL;
}

void
	get_player(t_player *player, char *line)
{
	if (ft_strnstr_eq(line, "p2", 15) == 1)
		ini_player(player, 'X', 'O');
	else
		ini_player(player, 'O', 'X');
}

int
	get_map(t_map *map_info, char *line)
{
	int		i;

	i = 0;
	if ((int)ft_strlen(line) < 8)
		return (0);
	map_info->nl = ft_atoi(line + 8);
	i = ft_intlen(map_info->nl);
	if ((int)ft_strlen(line) < (8 + i))
		return (0);
	map_info->nc = ft_atoi(line + 8 + i);
	if ((get_next_line(0, &line)) <= 0)
		return (0);
	ft_strdel(&line);
	if (!(map_info->map = (char **)malloc(sizeof(char *) * (map_info->nl + 1))))
		return (0);
	i = 0;
	while (i < map_info->nl && get_next_line(0, &line) > 0)
	{
		map_info->map[i] = ft_strsub(line, 4, map_info->nc);
		map_info->map[i][map_info->nc] = '\0';
		ft_strdel(&line);
		if ((int)ft_strlen(map_info->map[i]) < map_info->nc)
			return (0);
		++i;
	}
	ft_strdel(&line);
	map_info->map[i] = NULL;
	return (1);
}
