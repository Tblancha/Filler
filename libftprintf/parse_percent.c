/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 21:29:13 by brjorgen          #+#    #+#             */
/*   Updated: 2020/01/07 22:25:51 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_type		g_get_type[256] = {
	['c'] = TYPE_C,
	['s'] = TYPE_S,
	['p'] = TYPE_P,
	['d'] = TYPE_D,
	['i'] = TYPE_D,
	['o'] = TYPE_O,
	['u'] = TYPE_U,
	['U'] = TYPE_U,
	['x'] = TYPE_X_MIN,
	['X'] = TYPE_X_MAJ,
	['f'] = TYPE_F,
	['%'] = TYPE_PERCENT,
};

static const int		g_get_flag[256] = {
	['#'] = DIESE,
	['+'] = PLUS,
	[' '] = SPACE,
	['-'] = MINUS,
	['0'] = ZERO,
	['.'] = PRECISION,
	['*'] = ETOILE,
	['h'] = CONV_H,
	['l'] = CONV_L_MIN,
	['L'] = CONV_L_MAJ,
	['j'] = CONV_J,
	['z'] = CONV_Z,
	['q'] = CONV_LL,
};

static int
	flag_is_number(char **str)
{
	int		number;

	number = 0;
	if (ft_isdigit(**str) && **str != '0')
	{
		number = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	return (number);
}

static void
	fill_conversion(t_info_data *data, char **str, int flag)
{
	if (g_get_flag[(int)(**str)] == flag)
	{
		if (flag == CONV_H)
			data->conversion = CONV_HH;
		else if (flag == CONV_L_MIN)
			data->conversion = CONV_LL;
		else
			data->conversion = flag;
		(*str)++;
	}
	else
		data->conversion = flag;
}

static void
	parse_flag(t_info_data *data, char **str)
{
	int	flag;

	flag = 0;
	data->padding = flag_is_number(str);
	while (*str && ((flag = g_get_flag[(int)(**str)]) || ft_isdigit(**str)))
	{
		if (ft_isdigit(**str) && (**str) != '0')
		{
			data->padding = flag_is_number(str);
			(*str)--;
		}
		(*str)++;
		if (flag == CONV_H || flag == CONV_L_MIN || flag == CONV_L_MAJ
				|| flag == CONV_J || flag == CONV_Z || flag == CONV_LL)
			fill_conversion(data, str, flag);
		else
		{
			data->flag = data->flag | flag;
			if (flag == PRECISION)
				data->precision = flag_is_number(str);
		}
	}
}

static void
	init_info_data(t_info_data *data)
{
	data->flag = 0;
	data->type = 0;
	data->padding = 0;
	data->precision = 0;
	data->conversion = 0;
	data->len_arg = 0;
	data->arg_int = 0;
	data->sign = 0;
	data->check = 0;
	data->last_char = 0;
}

void
	parse_percent(t_info_data *data, char **str)
{
	init_info_data(data);
	if (!(**str))
		return ;
	parse_flag(data, str);
	data->type = g_get_type[(int)(**str)];
	data->last_char = (**str);
	(*str)++;
}
