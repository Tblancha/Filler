/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:48:14 by tblancha          #+#    #+#             */
/*   Updated: 2020/02/12 04:22:10 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static inline void
	ini_piece(t_piece *piece)
{
	piece->nl = 0;
	piece->nc = 0;
	piece->nb_star = 0;
	piece->ref_nl = 0;
	piece->ref_nc = 0;
}

static inline void
	get_coordonnee(t_piece *piece, char **tmp)
{
	int		l;
	int		c;
	int		star_num;

	l = 0;
	c = 0;
	star_num = 0;
	while (l < piece->nl)
	{
		while (c < piece->nc)
		{
			if (tmp[l][c] == '*')
			{
				if (!(piece->piece[star_num] = (int *)malloc(sizeof(int) * 2)))
					return ;
				piece->piece[star_num][0] = l;
				piece->piece[star_num][1] = c;
				star_num++;
			}
			c++;
		}
		c = 0;
		l++;
	}
	piece->piece[star_num] = NULL;
}

static inline int
	search_min_max(t_piece *piece, int numero, char ret)
{
	int		i;
	int		x;
	int		max;

	i = 1;
	max = piece->piece[0][numero];
	x = piece->piece[0][numero];
	while (i < piece->nb_star)
	{
		if (x > piece->piece[i][numero])
			x = piece->piece[i][numero];
		if (max < piece->piece[i][numero])
			max = piece->piece[i][numero];
		i++;
	}
	if (ret == 'm')
		return (x);
	else
		return (max);
}

static inline void
	ajust_coordonnee(t_piece *piece)
{
	int		i;

	i = 0;
	piece->ref_nl = search_min_max(piece, 0, 'm');
	piece->ref_nc = search_min_max(piece, 1, 'm');
	if (piece->ref_nl > 0 || piece->ref_nc > 0)
	{
		while (i < piece->nb_star)
		{
			piece->piece[i][0] -= piece->ref_nl;
			piece->piece[i][1] -= piece->ref_nc;
			i++;
		}
	}
	piece->nl = search_min_max(piece, 0, 'u') + 1;
	piece->nc = search_min_max(piece, 1, 'u') + 1;
}

int
	get_piece(t_piece *piece, char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	ini_piece(piece);
	if ((int)ft_strlen(line) < 6)
		return (0);
	piece->nl = ft_atoi(line + 6);
	if ((int)ft_strlen(line) < (6 + ft_intlen(piece->nl)))
		return (0);
	piece->nc = ft_atoi(line + 6 + ft_intlen(piece->nl));
	if (!(tmp = (char **)malloc(sizeof(char *) * (piece->nl + 1))))
		return (0);
	while (i < piece->nl)
	{
		get_next_line(0, &line);
		tmp[i] = ft_strdup(line);
		piece->nb_star += ft_count_char(tmp[i], '*');
		i++;
		ft_strdel(&line);
	}
	if (!(piece->piece = (int **)malloc(sizeof(int*) * (piece->nb_star + 1))))
		return (0);
	get_coordonnee(piece, tmp);
	free_tmp(tmp, piece->nl);
	ajust_coordonnee(piece);
	return (1);
}
