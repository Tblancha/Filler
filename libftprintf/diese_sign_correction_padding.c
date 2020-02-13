/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diese_sign_correction_padding.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:34:48 by tblancha          #+#    #+#             */
/*   Updated: 2019/12/26 19:34:52 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char
	*correction_precision_padding_flag_zero(t_info_data *data)
{
	if (data->flag & PRECISION)
	{
		if (data->precision < data->len_arg)
		{
			while (*data->arg_str == '0')
			{
				data->arg_str += 1;
				data->len_arg--;
				if (data->padding > 0)
					data->padding++;
			}
		}
	}
	if (data->sign == 1)
		data->padding--;
	return (data->arg_str);
}

void
	handler_signe_or_flag_plus(t_buff *buff, t_info_data *data)
{
	if (data->flag & ZERO && data->check == 0)
	{
		if (data->sign == 1)
			ft_putchar_buff(buff, '-');
		else if (data->flag & PLUS)
			ft_putchar_buff(buff, '+');
	}
	else if ((!(data->flag & ZERO)) && data->check == 1)
	{
		if (data->sign == 1)
			ft_putchar_buff(buff, '-');
		else if (data->flag & PLUS)
			ft_putchar_buff(buff, '+');
	}
	data->check = 1;
}

void
	prefix_router(t_buff *buff, t_info_data *data)
{
	if ((data->arg_str[0] == 0 || data->arg_str[0] == '0')
			&& (data->type != TYPE_O && data->type != TYPE_P))
		return ;
	if (data->type == TYPE_X_MAJ)
		ft_putstr_buff(buff, "0X");
	else if (data->type == TYPE_X_MIN || data->type == TYPE_P)
		ft_putstr_buff(buff, "0x");
	else if (data->type == TYPE_O)
	{
		if (data->arg_str[0] != '0')
			ft_putchar_buff(buff, '0');
	}
}
