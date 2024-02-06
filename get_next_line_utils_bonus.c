/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:03:07 by antoinejour       #+#    #+#             */
/*   Updated: 2024/01/11 17:35:15 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		lenght;
	int		i;
	char	*stash;

	if (!s1 || !s2)
		return (NULL);
	lenght = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	stash = malloc(sizeof(*s1) * (lenght + 1));
	if (!stash)
		return (NULL);
	i = 0;
	while (*s1)
		stash[i++] = *s1++;
	while (*s2)
		stash[i++] = *s2++;
	stash[i] = '\0';
	return (stash);
}

char	*ft_substr(char const *line, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	i = 0;
	j = 0;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (line[i])
	{
		if (i >= start && j < len)
		{
			substr[j] = line[i];
			j++;
		}
		i++;
	}
	substr[j] = 0;
	return (substr);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (str);
		i++;
	}
	return (NULL);
}
