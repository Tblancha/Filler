/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_eq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:07:19 by tblancha          #+#    #+#             */
/*   Updated: 2020/01/15 00:08:16 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnstr_eq(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		len_needle;

	i = 0;
	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return (1);
	while (haystack[i] && (i + len_needle <= len))
	{
		if (ft_strncmp(haystack + i, needle, len_needle) == 0)
			return (1);
		i++;
	}
	return (0);
}
