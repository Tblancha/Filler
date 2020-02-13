/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:32:38 by tblancha          #+#    #+#             */
/*   Updated: 2020/01/07 22:11:50 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_type_c_zero(t_buff *buff)
{
	flush_buff(buff);
	ft_putchar(0);
	buff->len += 1;
}

void		apply_precision_c(t_buff *buff, t_info_data *data)
{
	if (data->flag & PRECISION)
	{
		if (data->precision >= 1)
		{
			if (data->arg_int == 0)
				print_type_c_zero(buff);
			else
				ft_putchar_buff(buff, data->arg_int);
		}
		else
			buff->len += 1;
	}
	else
	{
		if (data->arg_int == 0)
			print_type_c_zero(buff);
		else
			ft_putchar_buff(buff, data->arg_int);
	}
}

void		apply_precision_s(t_buff *buff, t_info_data *data)
{
	if (data->flag & PRECISION)
	{
		if (data->precision < data->len_arg)
			ft_putnstr_buff(buff, data->arg_str, data->precision);
		else
			ft_putstr_buff(buff, data->arg_str);
	}
	else
		ft_putstr_buff(buff, data->arg_str);
}

void		apply_precision_pdiouxxmaj(t_buff *buff, t_info_data *data)
{
	if (data->type == TYPE_O && (data->flag & DIESE))
		data->precision--;
	if (data->flag & PRECISION)
		if (data->precision > data->len_arg)
			ft_repeat_char_buff(buff, '0',
					(data->precision - data->len_arg - data->sign));
	ft_putstr_buff(buff, data->arg_str);
}
