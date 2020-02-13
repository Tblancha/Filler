/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_va_arg_to_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 05:13:54 by tblancha          #+#    #+#             */
/*   Updated: 2019/12/26 19:34:06 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	va_arg_type_o(va_list arg, t_info_data *data)
{
	uintmax_t		number;

	if (data->conversion & CONV_HH)
		number = (unsigned char)va_arg(arg, int);
	else if (data->conversion & CONV_H)
		number = (unsigned short)va_arg(arg, int);
	else if (data->conversion & CONV_LL)
		number = (unsigned long long int)va_arg(arg, unsigned long long int);
	else if (data->conversion & CONV_L_MIN)
		number = (unsigned long)va_arg(arg, unsigned long int);
	else if (data->conversion & CONV_J)
		number = (uintmax_t)va_arg(arg, uintmax_t);
	else if (data->conversion & CONV_Z)
		number = (size_t)va_arg(arg, size_t);
	else
		number = (unsigned int)va_arg(arg, unsigned int);
	data->arg_str = convert_to_base_uintmax_t(number, "01234567");
}

void
	va_arg_type_u(va_list arg, t_info_data *data)
{
	uintmax_t		number;

	if (data->conversion & CONV_HH)
		number = (unsigned char)va_arg(arg, int);
	else if (data->conversion & CONV_H)
		number = (unsigned short)va_arg(arg, int);
	else if (data->conversion & CONV_LL)
		number = (unsigned long long int)va_arg(arg, unsigned long long int);
	else if (data->conversion & CONV_L_MIN)
		number = (unsigned long)va_arg(arg, unsigned long int);
	else if (data->conversion & CONV_J)
		number = (uintmax_t)va_arg(arg, uintmax_t);
	else if (data->conversion & CONV_Z)
		number = (size_t)va_arg(arg, size_t);
	else
		number = (unsigned int)va_arg(arg, unsigned int);
	data->arg_str = convert_to_base_uintmax_t(number, "0123456789");
}

void
	va_arg_type_x_min(va_list arg, t_info_data *data)
{
	uintmax_t		number;

	if (data->conversion & CONV_HH)
		number = (unsigned char)va_arg(arg, int);
	else if (data->conversion & CONV_H)
		number = (unsigned short)va_arg(arg, int);
	else if (data->conversion & CONV_LL)
		number = (unsigned long long int)va_arg(arg, unsigned long long int);
	else if (data->conversion & CONV_L_MIN)
		number = (unsigned long)va_arg(arg, unsigned long int);
	else if (data->conversion & CONV_J)
		number = (uintmax_t)va_arg(arg, uintmax_t);
	else if (data->conversion & CONV_Z)
		number = (size_t)va_arg(arg, size_t);
	else
		number = (unsigned int)va_arg(arg, unsigned int);
	data->arg_str = convert_to_base_uintmax_t(number, "0123456789abcdef");
}

void
	va_arg_type_x_maj(va_list arg, t_info_data *data)
{
	uintmax_t		number;

	if (data->conversion & CONV_HH)
		number = (unsigned char)va_arg(arg, int);
	else if (data->conversion & CONV_H)
		number = (unsigned short)va_arg(arg, int);
	else if (data->conversion & CONV_LL)
		number = (unsigned long long int)va_arg(arg, unsigned long long int);
	else if (data->conversion & CONV_L_MIN)
		number = (unsigned long)va_arg(arg, unsigned long int);
	else if (data->conversion & CONV_J)
		number = (uintmax_t)va_arg(arg, uintmax_t);
	else if (data->conversion & CONV_Z)
		number = (size_t)va_arg(arg, size_t);
	else
		number = (unsigned int)va_arg(arg, unsigned int);
	data->arg_str = convert_to_base_uintmax_t(number, "0123456789ABCDEF");
}

void
	va_arg_type_f(va_list arg, t_info_data *data)
{
	long double		number;

	if (data->conversion & CONV_L_MIN)
		number = va_arg(arg, long double);
	else if (data->conversion & CONV_L_MAJ)
		number = va_arg(arg, long double);
	else
		number = va_arg(arg, double);
	data->arg_str = convert_float(number);
}
