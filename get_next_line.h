/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:38:05 by antoinejour       #+#    #+#             */
/*   Updated: 2024/01/11 16:57:52 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_cleanline_updatesafe(char *line);
char	*ft_get_line(char *safe, char *buf, int fd);
char	*ft_strchr(char *str, char c);
char	*ft_substr(char const *line, unsigned int start, size_t len);

#endif
