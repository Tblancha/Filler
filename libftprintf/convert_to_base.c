/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 21:26:53 by brjorgen          #+#    #+#             */
/*   Updated: 2020/01/07 23:08:15 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char
	*convert_to_base_uintmax_t(uintmax_t number, char *base)
{
	int				len_base;
	static char		buff_containing_data[125];
	char			*converted_num;

	len_base = ft_strlen(base);
	converted_num = &buff_containing_data[124];
	*converted_num = '\0';
	while (number != 0)
	{
		*--converted_num = base[number % len_base];
		number = number / len_base;
	}
	if (*converted_num == '\0')
		*--converted_num = '0';
	return (converted_num);
}

char
	*convert_to_base_intmax_t(intmax_t number, char *base)
{
	int				len_base;
	static char		buff_containing_data[125];
	char			*converted_num;
	int				signe;

	len_base = ft_strlen(base);
	converted_num = &buff_containing_data[124];
	*converted_num = '\0';
	signe = (number < 0) ? 1 : 0;
	while (number != 0)
	{
		*--converted_num = base[ft_abs(number % len_base)];
		number = number / len_base;
	}
	if (signe)
		*--converted_num = '-';
	if (*converted_num == '\0')
		*--converted_num = '0';
	return (converted_num);
}

char
	*convert_float(long double number)
{
	long			p_entier;
	long			p_mantisse;
	static char		*data;
	char			*data2;

	p_entier = (long)number;
	number -= (long double)p_entier;
	number *= 1000000;
	p_mantisse = (long)number;
	data = convert_to_base_intmax_t(p_mantisse, "0123456789");
	*--data = '.';
	data2 = convert_to_base_intmax_t(p_entier, "0123456789");
	p_entier = ft_strlen(data2);
	p_mantisse = p_entier;
	while (--p_entier)
		data2++;
	while (p_mantisse)
	{
		*--data = *data2--;
		--p_mantisse;
	}
	return (data);
}
