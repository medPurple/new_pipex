/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:52:13 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/13 15:03:34 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup[1024];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	backup[fd] = ft_line_read(fd, backup[fd]);
	if (!backup[fd])
		return (NULL);
	line = ft_get_line(backup[fd]);
	backup[fd] = ft_backup(backup[fd]);
	return (line);
}

char	*ft_line_read(int fd, char *backup)
{
	char	*buffer;
	int		trigger;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	trigger = 1;
	while (!ft_strchr(backup, '\n') && trigger != 0)
	{
		trigger = read(fd, buffer, BUFFER_SIZE);
		if (trigger == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[trigger] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	return (backup);
}

char	*ft_get_line(char *backup)
{
	int		i;
	char	*line;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_backup(char *backup)
{
	int		i;
	int		c;
	char	*buff;
	int		len;

	len = ft_strlen(backup);
	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	buff = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!buff)
		return (NULL);
	i++;
	c = 0;
	while (backup[i])
		buff[c++] = backup[i++];
	buff[c] = '\0';
	free (backup);
	return (buff);
}
