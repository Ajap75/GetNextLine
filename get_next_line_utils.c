/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:03:07 by antoinejour       #+#    #+#             */
/*   Updated: 2024/01/11 13:46:04 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
/*malloc a new string which is the union of s1 et s2*/

char	*ft_substr(char const *line, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*substr;

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

/*A substr is malloc and extract from a string (line), the substr begin at "start" and end either at the end of line 
or once we've reached the max size of substr = "len"*/

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
/*Find a character in a string. If the char is found, the string is returned*/
