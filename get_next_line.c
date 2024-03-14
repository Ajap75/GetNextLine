/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:48:59 by antoinejour       #+#    #+#             */
/*   Updated: 2024/01/11 15:28:22 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
/*The read function load the buf with Buffer_size bytes,
and return the number of bytes actually readed. It can be less than buffer size,
if the function has reach the end of the file,
or return a negative number in case of an error. 
We need a safe to store the readed bytes. If the safe doesn't exist yet we creat it.
We null terminate buff which store the bytes readed by the read function. 
Safe store, every bytes readed. (truncated of what have been returned
by the get_next_line function, thanks to ft_cleanline_updatesafe (char *line) function.
Safe need to be update at every call of the function by adding what have been read at this call
to what has been stored. --> tmp= safe / then / strjoin(tmp, buf);
Of course we need to free tmp and set Tmp to null at the end.*/
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
/*This function is the center of everything, the tricky part. 
The name is pretty clear. It has two main goals. 
1) we go through the line searching for \n.
When a \n is found, it means that WE HAVE A LINE. 
2) Update safe in GNl by extracting with substr everything
after the \n from line (i + 1) to leave the \n in the line. 
1) Then Update the line(the return of Gnl)
by truncating the line at /n --> line[i + 1] = '\0'. 
*/

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*safe;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_get_line(safe, buf, fd);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	safe = ft_cleanline_updatesafe(line);
	return (line);
}
/*The get next line function aim to read bytes
from a file descriptor and return a line.
line is ended by a /n or /0 if it's the end of the file.
The function has to keep in memory everything it has already
read during the last call, minus what have been return. 
For example if in what it has readed (BUFFER_size) there is a \n.
It has to be abble to return the bytes readed to \n. But also to keep in memory,
the bytes readed between /n and buffer_size to store every extra bytes read and
to add them at the begining of the next return (the next line)
when the function will be call again. And so on. 
/*
int	main(void)
{
	char	*line;
	int		fd;

	fd = open("Texte.txt", O_RDONLY);
	if (fd < 0)
		return (101);
	line = get_next_line(fd);
	while (1)
	{
		if (line == NULL)
			break ;
		printf("|%s|", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
*/
