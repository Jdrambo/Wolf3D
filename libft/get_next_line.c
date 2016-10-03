/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <jde-rus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 13:48:50 by jde-rus           #+#    #+#             */
/*   Updated: 2014/12/17 17:00:59 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(int const fd, char *buff, char *ptr[fd])
{
	int		r;
	char	*c;
	char	*tmp;

	while (!(c = ft_strchr(ptr[fd], '\n')) &&\
			(r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		tmp = ptr[fd];
		ptr[fd] = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	ft_strdel(&buff);
	if (r == -1)
		return (-1);
	if (!c && r == 0)
		return (0);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char	*ptr[256];
	int			ret;
	char		*buff;
	char		*tmp;

	buff = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || buff == NULL)
		return (-1);
	if (ptr[fd] == NULL)
		ptr[fd] = ft_strnew(1);
	ret = get_line(fd, buff, &*ptr);
	if (ret == -1)
		return (-1);
	if (ret == 0)
	{
		*line = ptr[fd];
		ptr[fd] = NULL;
		return (0);
	}
	*line = ft_strsub(ptr[fd], 0, (ft_strchr(ptr[fd], '\n') - ptr[fd]));
	tmp = ptr[fd];
	ptr[fd] = ft_strdup(ft_strchr(tmp, '\n') + 1);
	ft_strdel(&tmp);
	return (1);
}
