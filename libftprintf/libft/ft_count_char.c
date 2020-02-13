/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 01:47:23 by tblancha          #+#    #+#             */
/*   Updated: 2020/01/17 01:51:21 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_char(char *str, char star)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == star)
			n++;
		i++;
	}
	return (n);
}
