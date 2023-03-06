/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:42:52 by sycourbi          #+#    #+#             */
/*   Updated: 2022/12/08 17:40:19 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_end(char *stock);
char	*ft_cop_line(char *stock);
char	*ft_read_line(char *stock, int fd);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strlcpy(char *dest, char *src, int size);
void	ft_strlcat(char *dest, char *src, int size);
int		ft_strlen(char *str);
int		ft_search_return(char *s);
char	*get_next_line(int fd);

#endif
