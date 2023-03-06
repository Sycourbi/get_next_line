/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:10:24 by sycourbi          #+#    #+#             */
/*   Updated: 2022/12/09 17:26:05 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_end(char *stock)
{
	char	*tmp;
	int		i;

	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	if (stock[i] == '\0')
	{
		free(stock);
		return (NULL);
	}
	i++;
	tmp = malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, &stock[i], (ft_strlen(stock) - i + 1));
	free(stock);
	return (tmp);
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
	if (ret < 0)
		return (NULL);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stock || ft_strchr(stock, '\n') == NULL)
		stock = ft_read_line(stock, fd);
	if (!stock)
		return (NULL);
	line = ft_cop_line(stock);
	if (line)
		stock = ft_end(stock);
	else
		free(stock);
	return (line);
}
