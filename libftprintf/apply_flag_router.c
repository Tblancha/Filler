/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag_router.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:29:02 by tblancha          #+#    #+#             */
/*   Updated: 2019/12/26 19:29:27 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	apply_flag_router_c(t_buff *buff, t_info_data *data)
{
	if (data->flag & SPACE)
		ft_putchar_buff(buff, ' ');
	if (data->flag & ZERO)
		ft_repeat_char_buff(buff, '0', data->padding);
	else if (!(data->flag & MINUS))
		ft_repeat_char_buff(buff, ' ', data->padding);
	apply_precision_c(buff, data);
	if (data->flag & MINUS)
		ft_repeat_char_buff(buff, ' ', data->padding);
}

void
	apply_flag_router_s(t_buff *buff, t_info_data *data)
{
	data->arg_str = correction_precision_padding_flag_zero(data);
	if (data->flag & SPACE)
		ft_putchar_buff(buff, ' ');
	if (data->flag & ZERO)
		ft_repeat_char_buff(buff, '0', data->padding);
	else if (!(data->flag & MINUS))
		ft_repeat_char_buff(buff, ' ', data->padding);
	apply_precision_s(buff, data);
	if (data->flag & MINUS)
		ft_repeat_char_buff(buff, ' ', data->padding);
}

void
	apply_flag_router_other(t_buff *buff, t_info_data *data)
{
	data->arg_str = correction_precision_padding_flag_zero(data);
	if (data->flag & SPACE)
		if (data->sign == 0)
			ft_putchar_buff(buff, ' ');
	handler_signe_or_flag_plus(buff, data);
	if ((data->flag & DIESE) && (data->flag & ZERO))
		prefix_router(buff, data);
	if (data->flag & ZERO)
		ft_repeat_char_buff(buff, '0', data->padding);
	else if (!(data->flag & MINUS))
		ft_repeat_char_buff(buff, ' ', data->padding);
	handler_signe_or_flag_plus(buff, data);
	if ((data->flag & DIESE) && !(data->flag & ZERO))
		prefix_router(buff, data);
	apply_precision_pdiouxxmaj(buff, data);
	if (data->flag & MINUS)
		ft_repeat_char_buff(buff, ' ', data->padding);
}
