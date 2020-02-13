/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:35:07 by tblancha          #+#    #+#             */
/*   Updated: 2020/01/07 21:53:29 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf_dispatch_type
	pf_dispatch_type(int type)
{
	static t_pf_dispatch_type	array[NUMBER_ELEMENT_ENUM];

	array[TYPE_C] = dispatch_type_c;
	array[TYPE_S] = dispatch_type_s;
	array[TYPE_P] = dispatch_type_p;
	array[TYPE_D] = dispatch_type_d;
	array[TYPE_O] = dispatch_type_o;
	array[TYPE_U] = dispatch_type_u;
	array[TYPE_X_MIN] = dispatch_type_x_min;
	array[TYPE_X_MAJ] = dispatch_type_x_maj;
	array[TYPE_F] = dispatch_type_f;
	return (array[type]);
}

void
	dispatch_type_c(va_list arg, t_buff *buff, t_info_data *data)
{
	va_arg_type_c(arg, data);
	ignore_flag_for_c_s(data);
	data->len_arg = 1;
	data->padding = real_value_of_padding_c_s(data);
	apply_flag_router_c(buff, data);
}

void
	dispatch_type_s(va_list arg, t_buff *buff, t_info_data *data)
{
	va_arg_type_s(arg, data);
	ignore_flag_for_c_s(data);
	data->len_arg = ft_strlen(data->arg_str);
	data->padding = real_value_of_padding_c_s(data);
	apply_flag_router_s(buff, data);
}

void
	dispatch_type_p(va_list arg, t_buff *buff, t_info_data *data)
{
	va_arg_type_p(arg, data);
	ignore_flag_for_p(data);
	data->len_arg = ft_strlen(data->arg_str);
	data->padding = real_value_of_padding_pdiuxxmaj(data);
	apply_flag_router_other(buff, data);
}

void
	dispatch_type_d(va_list arg, t_buff *buff, t_info_data *data)
{
	va_arg_type_d(arg, data);
	ignore_flag_for_d(data);
	data->len_arg = ft_strlen(data->arg_str);
	data->padding = real_value_of_padding_pdiuxxmaj(data);
	apply_flag_router_other(buff, data);
}
