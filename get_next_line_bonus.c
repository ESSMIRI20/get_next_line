/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:24:46 by oessmiri          #+#    #+#             */
/*   Updated: 2024/12/03 09:30:49 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*extract_line(char *storage)
{
	char	*line;
	int		i;

	if (!storage || !*storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = ft_substr(storage, 0, i);
	return (line);
}

char	*update_storage(char *storage)
{
	char	*new_storage;
	int		i;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	new_storage = ft_substr(storage, i + 1, ft_strlen(storage) - i - 1);
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = read_file(fd, storage[fd]);
	if (!storage[fd] || *storage[fd] == '\0')
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	line = extract_line(storage[fd]);
	storage[fd] = update_storage(storage[fd]);
	return (line);
}
