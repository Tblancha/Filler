/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 21:55:12 by tblancha          #+#    #+#             */
/*   Updated: 2020/01/07 22:21:16 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void
	init_struct_buff(t_buff *buff)
{
	buff->index = 0;
	buff->len = 0;
	ft_bzero(buff->buffer, BUFF_SIZE_2);
}

static void
	init_struct_data(t_info_data *data)
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
}

static void
	print_type_percent(t_buff *buff, t_info_data *data)
{
	if (data->padding > 1 && !(data->flag & MINUS))
		ft_repeat_char_buff(buff, ' ', (data->padding - 1));
	ft_putchar_buff(buff, '%');
	if (data->padding > 1 && (data->flag & MINUS))
		ft_repeat_char_buff(buff, ' ', (data->padding - 1));
}

static void
	ft_reductor(va_list *arg, char *str, t_buff *buff, t_info_data *data)
{
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_buff(buff, *str);
			str++;
		}
		else
		{
			str++;
			init_struct_data(data);
			parse_percent(data, &str);
			if (data->flag & ETOILE)
				data->padding = (int)va_arg(*arg, int);
			if (data->type == TYPE_NONE)
				ft_putchar_buff(buff, data->last_char);
			else if (data->type == TYPE_PERCENT)
				print_type_percent(buff, data);
			else
				pf_dispatch_type(data->type)(*arg, buff, data);
		}
	}
}

int
	ft_printf(const char *format, ...)
{
	char			*str;
	t_buff			buff;
	va_list			arg;
	t_info_data		data;

	if (!format)
	{
		ft_putstr("Usage: ft_printf(\"Put a string here\")");
		return (0);
	}
	str = (char *)format;
	va_start(arg, format);
	init_struct_buff(&buff);
	ft_reductor(&arg, str, &buff, &data);
	flush_buff(&buff);
	return (buff.len);
}
