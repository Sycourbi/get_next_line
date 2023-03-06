/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:42:07 by sycourbi          #+#    #+#             */
/*   Updated: 2022/12/09 12:47:00 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_end(char *stock);
char	*ft_cop_line(char *stock);
char	*ft_read_line(char *stock, int fd);
char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
void	ft_strlcpy(char *dest, char *src, int size);
void	ft_strlcat(char *dest, char *src, int size);

#endif
