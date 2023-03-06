/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:02:32 by sycourbi          #+#    #+#             */
/*   Updated: 2022/12/09 13:04:22 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_end(char *stock)
{
	char		*end;
	long int	i;
	long int	j;

	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	if (stock[i] == '\0')
	{
		free(stock);
		return (NULL);
	}
	i++;
	j = ft_strlen(stock);
	end = malloc(sizeof(char) * (j - i + 1));
	if (!end)
		return (NULL);
	ft_strlcpy(end, &stock[i], (j - i + 1));
	free(stock);
	return (end);
}

char	*ft_cop_line(char *stock)
{
	long int	i;
	char		*line;

	i = 0;
	if (!stock[0])
		return (NULL);
	while (stock[i] != '\n' && stock[i])
		i++;
	if (stock[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_strlcpy(line, stock, i + 1);
	return (line);
}

char	*ft_read_line(char *stock, int fd)
{
	char	*buf;
	int		ret;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	ret = 1;
	while (ret > 0 && ft_strchr(buf, '\n') == NULL)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret > 0)
		{
			buf[ret] = '\0';
			stock = ft_strjoin(stock, buf);
			if (!stock)
				return (free(buf), NULL);
		}
	}
	free(buf);
	if (ret == -1)
		return (NULL);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4096)
		return (NULL);
	if (!stock[fd] || ft_strchr(stock[fd], '\n') == NULL)
		stock[fd] = ft_read_line(stock[fd], fd);
	if (!stock[fd])
		return (NULL);
	line = ft_cop_line(stock[fd]);
	if (line)
		stock[fd] = ft_end(stock[fd]);
	else
		free(stock[fd]);
	return (line);
}
