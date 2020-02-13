/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignore_flag2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 22:21:59 by tblancha          #+#    #+#             */
/*   Updated: 2020/01/07 22:22:02 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ignore_flag_for_d(t_info_data *data)
{
	ignore_flag_priority(data, MINUS, ZERO);
	ignore_flag_priority(data, PRECISION, ZERO);
	ignore_flag_priority(data, PLUS, SPACE);
	ignore_flag(data, DIESE);
}

void	ignore_flag_for_o_x_xmaj(t_info_data *data)
{
	ignore_flag_priority(data, MINUS, ZERO);
	ignore_flag_priority(data, PRECISION, ZERO);
	ignore_flag(data, PLUS);
	ignore_flag(data, SPACE);
}

void	ignore_flag_for_float(t_info_data *data)
{
	ignore_flag_priority(data, MINUS, ZERO);
	ignore_flag_priority(data, PRECISION, ZERO);
}

void	ignore_flag_for_u(t_info_data *data)
{
	ignore_flag_priority(data, MINUS, ZERO);
	ignore_flag_priority(data, PRECISION, ZERO);
	ignore_flag(data, DIESE);
	ignore_flag(data, PLUS);
	ignore_flag(data, SPACE);
}

void	ignore_flag_for_c_s(t_info_data *data)
{
	ignore_flag(data, DIESE);
	ignore_flag(data, PLUS);
	ignore_flag(data, SPACE);
}
