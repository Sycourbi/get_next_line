/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:27:49 by sycourbi          #+#    #+#             */
/*   Updated: 2022/12/09 13:04:59 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_strlcat(char *dest, char *src, int size)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (dest[len] && len < size)
		len++;
	while (src[i] && len - i + 1 < size)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
}

void	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	ft_strlcat(new, s2, (i + 1));
	free(s1);
	if (!new)
		return (NULL);
	return (new);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	if (s[i] == c)
		return (&s[i]);
	return (NULL);
}
