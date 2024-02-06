/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:48:59 by antoinejour       #+#    #+#             */
/*   Updated: 2024/01/11 17:35:35 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

char	*ft_get_line(char *safe, char *buf, int fd)
{
	int		bytes_readed;
	char	*tmp;

	bytes_readed = 1;
	while (!ft_strchr(safe, '\n'))
	{
		bytes_readed = read(fd, buf, BUFFER_SIZE);
		if (bytes_readed < 0)
			return (0);
		else if (bytes_readed == 0)
			break ;
		if (!safe)
		{
			safe = malloc(sizeof(char) * 1);
			if (!safe)
				return (0);
			safe[0] = '\0';
		}
		buf[bytes_readed] = '\0';
		tmp = safe;
		safe = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
	}
	return (safe);
}

char	*ft_cleanline_updatesafe(char *line)
{
	int		i;
	char	*dest;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	dest = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*dest == '\0')
	{
		free(dest);
		dest = NULL;
	}
	line[i + 1] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*safe[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_get_line(safe[fd], buf, fd);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	safe[fd] = ft_cleanline_updatesafe(line);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;

// 	fd1 = open("Texte.txt", O_RDONLY);
// 	fd2 = open("Texte2.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 5)
// 	{
// 		line = get_next_line(fd1);
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
