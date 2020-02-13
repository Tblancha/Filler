/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 22:47:07 by tblancha          #+#    #+#             */
/*   Updated: 2020/01/24 12:32:46 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_realloc_line(char **line, ssize_t buf, ssize_t *len)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * *len)))
		return (0);
	tmp = ft_strncpy(tmp, *line, (size_t)buf);
	ft_memdel((void **)line);
	*len = *len * 2;
	if (!(*line = (char *)malloc(sizeof(char) * *len)))
		return (0);
	ft_bzero((void **)*line, (size_t)*len);
	*line = ft_strncpy(*line, tmp, buf);
	ft_memdel((void **)&tmp);
	return (1);
}

int			ft_endgnl(char **line, ssize_t buf)
{
	if (line[0][0] != '\0')
	{
		line[0][buf] = '\0';
		return (1);
	}
	else
	{
		line[0] = (char*)malloc(sizeof(char) + 1);
		line[0][0] = '\0';
		return (0);
	}
}

int			ft_ret1(char **line, ssize_t buf, ssize_t *i)
{
	line[0][buf] = '\0';
	i[0]++;
	return (1);
}

void		ft_read(ssize_t *i, ssize_t *nbyte, char *tpm, int fd)
{
	if (*i == *nbyte)
	{
		*nbyte = read(fd, tpm, BUFF_SIZE);
		*i = 0;
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	gnl;
	t_var			var;

	if (fd < 0 || BUFF_SIZE < 1 || fd > 4864)
		return (-1);
	var.len = 128;
	var.buf = 0;
	if (!(*line = (char*)malloc(sizeof(char) * var.len)))
		return (-1);
	ft_bzero((void *)line[0], (size_t)var.len);
	while (gnl.nbyte[fd] >= 0)
	{
		ft_read(&gnl.i[fd], &gnl.nbyte[fd], gnl.tmp[fd], fd);
		if (gnl.nbyte[fd] == 0)
			return (ft_endgnl(line, var.buf));
		if (gnl.tmp[fd][gnl.i[fd]] == '\n')
			return (ft_ret1(line, var.buf, &gnl.i[fd]));
		line[0][var.buf++] = gnl.tmp[fd][gnl.i[fd]++];
		if (var.buf == var.len - 1)
			if (!ft_realloc_line(line, var.buf, &var.len))
				return (-1);
	}
	return (-1);
}
