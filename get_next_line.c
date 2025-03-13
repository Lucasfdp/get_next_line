/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:39:56 by luferna3          #+#    #+#             */
/*   Updated: 2025/03/13 03:21:38 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;

	if (!storage)
		storage = ft_calloc(sizeof(char), 1);
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(buffer), free(storage), NULL);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(storage), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*add_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[0])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i);
	if (!line)
		return (free(line), free(buffer), NULL);
	if (buffer[i] == '\n')
		line[i] = buffer[i];
	return (line);
}

char	*clean(char *storage)
{
	char	*storage_new;
	int		len;

	len = 0;
	while (storage[len] != '\0' && storage[len] != '\n')
		len++;
	storage_new = ft_substr(storage, len + 1, ft_strlen(storage) - len);
	if (!storage_new)
		return (free(storage), free(storage_new), NULL);
	free(storage);
	return (storage_new);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(sizeof(BUFFER_SIZE), 1);
	if (!ft_strchr(buffer, '\n'))
		buffer = read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = add_line(buffer);
	buffer = clean(buffer);
	return (line);
}

// int main(void)
// {
//     int fd = open("ex.txt", O_RDONLY);
//     char *line = NULL;

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("Line: %s\n", line);
//         free(line);
//     }

//     close(fd);
//     return (0);
// }