/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_va_arg_to_str2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 05:13:54 by tblancha          #+#    #+#             */
/*   Updated: 2020/01/07 23:08:23 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	va_arg_type_c(va_list arg, t_info_data *data)
{
	data->arg_int = (int)va_arg(arg, int);
}

void
	va_arg_type_s(va_list arg, t_info_data *data)
{
	data->arg_str = (char*)va_arg(arg, char *);
	if (data->arg_str == NULL)
		data->arg_str = "(null)";
}

void
	va_arg_type_p(va_list arg, t_info_data *data)
{
	data->arg_str = convert_to_base_intmax_t(va_arg(arg, intmax_t),
	"0123456789abcdef");
}

void
	va_arg_type_d(va_list arg, t_info_data *data)
{
	intmax_t	number;

	data->sign = 0;
	if (data->conversion & CONV_HH)
		number = (char)va_arg(arg, int);
	else if (data->conversion & CONV_H)
		number = (short)va_arg(arg, int);
	else if (data->conversion & CONV_L_MIN)
		number = (long int)va_arg(arg, long int);
	else if (data->conversion & CONV_LL)
		number = (long long int)va_arg(arg, long long int);
	else if (data->conversion & CONV_Z)
		number = (size_t)va_arg(arg, size_t);
	else if (data->conversion & CONV_J)
		number = (intmax_t)va_arg(arg, intmax_t);
	else
		number = (int)va_arg(arg, int);
	if (number < 0)
		data->sign = 1;
	data->arg_str = convert_to_base_uintmax_t(ft_abs(number), "0123456789");
}
