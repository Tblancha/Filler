/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_type2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 21:53:57 by tblancha          #+#    #+#             */
/*   Updated: 2020/01/07 21:54:11 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dispatch_type_o(va_list arg, t_buff *buff, t_info_data *data)
{
	va_arg_type_o(arg, data);
	ignore_flag_for_o_x_xmaj(data);
	data->len_arg = ft_strlen(data->arg_str);
	data->padding = real_value_of_padding_o(data);
	apply_flag_router_other(buff, data);
}

void	dispatch_type_u(va_list arg, t_buff *buff, t_info_data *data)
{
	va_arg_type_u(arg, data);
	ignore_flag_for_u(data);
	data->len_arg = ft_strlen(data->arg_str);
	data->padding = real_value_of_padding_pdiuxxmaj(data);
	apply_flag_router_other(buff, data);
}

void	dispatch_type_x_min(va_list arg, t_buff *buff, t_info_data *data)
{
	va_arg_type_x_min(arg, data);
	ignore_flag_for_o_x_xmaj(data);
	data->len_arg = ft_strlen(data->arg_str);
	data->padding = real_value_of_padding_pdiuxxmaj(data);
	apply_flag_router_other(buff, data);
}

void	dispatch_type_x_maj(va_list arg, t_buff *buff, t_info_data *data)
{
	va_arg_type_x_maj(arg, data);
	ignore_flag_for_o_x_xmaj(data);
	data->len_arg = ft_strlen(data->arg_str);
	data->padding = real_value_of_padding_pdiuxxmaj(data);
	apply_flag_router_other(buff, data);
}

void	dispatch_type_f(va_list arg, t_buff *buff, t_info_data *data)
{
	va_arg_type_f(arg, data);
	ignore_flag_for_float(data);
	data->len_arg = ft_strlen(data->arg_str);
	data->padding = real_value_of_padding_pdiuxxmaj(data);
	apply_flag_router_other(buff, data);
}
