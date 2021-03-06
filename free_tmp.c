/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:40:20 by tblancha          #+#    #+#             */
/*   Updated: 2020/02/12 03:18:05 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_tmp(char **tmp, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		ft_strdel(&tmp[i]);
		++i;
	}
	free(tmp);
	tmp = NULL;
}
