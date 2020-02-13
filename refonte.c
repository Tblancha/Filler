#include "filler.h"

static void
	free_exit(t_map *map, t_piece *piece)
{
	free_all(map, piece);
	exit (0);
}

static int		check(t_player *player, t_map *map, t_piece *piece)
{
	if (player->en1 != 'O' && player->en1 != 'X')
		return (0);
	if (player->me1 != 'O' && player->me1 != 'X')
		return (0);
	if (map->nl <= 0 || map->nc <= 0)
		return (0);
	if (piece->nl <= 0 || piece->nc <= 0)
		return (0);
	if (piece->nb_star <= 0)
		return (0);
	return (1);
}

int		refonte(t_player *player, t_map *map, t_piece *piece)
{
	int		i;
	char	*line;
	int 	ret;

	i = 0;
	while ((ret = get_next_line(0, &line)) >= 0)
	{
		i++;
		if ((ft_strnstr_eq(line, "$$$ exec", 15) == 1)
		&& (ft_strnstr_eq(line, "tblancha", (int)ft_strlen(line)) == 1))
			get_player(player, line);
		if (ft_strnstr_eq(line, "Plateau", 15) == 1)
			if (!(get_map(map, line)))
				free_exit(map, piece);
		if (ft_strnstr_eq(line, "Piece", 7) == 1)
		{
			get_piece(piece, line);
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
		if (i > 20 || ret <= 0)
			return (0);
	}
	if (!check(player, map, piece))
		return (0);
	return (1);
}