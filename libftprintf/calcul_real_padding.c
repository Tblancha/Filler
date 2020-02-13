/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_real_padding.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:33:07 by tblancha          #+#    #+#             */
/*   Updated: 2019/12/26 19:33:12 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	real_value_of_padding_c_s(t_info_data *data)
{
	int	real_padding;

	real_padding = data->padding;
	if (data->precision >= data->len_arg
			|| !(data->flag & PRECISION))
		real_padding -= data->len_arg;
	else
		real_padding -= data->precision;
	if (real_padding < 0)
		real_padding = 0;
	return (real_padding);
}

int	real_value_of_padding_pdiuxxmaj(t_info_data *data)
{
	int		real_padding;

	real_padding = data->padding;
	if (data->flag & DIESE)
		real_padding -= 2;
	if (data->flag & SPACE)
		if (data->sign == 0)
			real_padding -= 1;
	if (data->flag & PLUS)
		if (data->sign == 0)
			real_padding -= 1;
	if (!(data->flag & SPACE) && !(data->flag & PLUS) && data->sign == 1)
	{
		real_padding -= 1;
		data->len_arg--;
	}
	if (data->precision > data->len_arg)
		real_padding -= data->precision - data->sign;
	else
		real_padding -= data->len_arg;
	if (real_padding < 0)
		real_padding = 0;
	return (real_padding);
}

int	real_value_of_padding_o(t_info_data *data)
{
	int		real_padding;

	real_padding = data->padding;
	if (data->flag & DIESE)
		real_padding -= 1;
	if (data->flag & SPACE)
		real_padding -= 1;
	if (data->precision >= data->len_arg)
		real_padding -= data->precision;
	else
		real_padding -= data->len_arg;
	if (real_padding < 0)
		real_padding = 0;
	return (real_padding);
}
