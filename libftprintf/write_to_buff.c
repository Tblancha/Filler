/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:55:16 by tblancha          #+#    #+#             */
/*   Updated: 2020/01/07 22:24:03 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	flush_buff(t_buff *buff)
{
	buff->len += ft_strlen(buff->buffer);
	ft_putstr(buff->buffer);
	ft_bzero(buff->buffer, BUFF_SIZE_2);
	buff->index = 0;
}

void
	ft_repeat_char_buff(t_buff *buff, char c, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_putchar_buff(buff, c);
}

void
	ft_putchar_buff(t_buff *buff, char c)
{
	if ((buff->index + 1) >= BUFF_SIZE_2)
		flush_buff(buff);
	buff->buffer[buff->index] = c;
	buff->index++;
}

void
	ft_putstr_buff(t_buff *buff, char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		ft_putchar_buff(buff, *str);
		str++;
	}
}

void
	ft_putnstr_buff(t_buff *buff, char *str, int n)
{
	if (!str)
		return ;
	while (*str && --n >= 0)
	{
		ft_putchar_buff(buff, *str);
		str++;
	}
}
