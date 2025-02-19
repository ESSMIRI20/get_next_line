/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:30:55 by oessmiri          #+#    #+#             */
/*   Updated: 2024/12/03 09:38:29 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t n, size_t size)
{
	void			*s;
	unsigned int	i;
	size_t			len;
	unsigned char	*ptr;

	len = n * size;
	i = 0;
	if (n == 0 || size == 0)
		return (malloc(1));
	s = (void *)malloc(n * size);
	if (s == NULL)
		return (NULL);
	ptr = (unsigned char *)s;
	while (len > 0)
	{
		ptr[i] = 0;
		i++;
		len--;
	}
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s = (char *)malloc((ft_strlen((char *) s1)
				+ ft_strlen((char *) s2)) * sizeof(char) + 1);
	if (s == NULL)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s[i + ft_strlen((char *) s1)] = s2[i];
		i++;
	}
	s[i + ft_strlen((char *) s1)] = '\0';
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		s_len;
	char		*str;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen((char *) s);
	if (start >= s_len)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (len > s_len - start)
		len = s_len - start;
	i = 0;
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	return (ft_substr(s, 0, ft_strlen((char *)s)));
}

char	*read_file(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;
	char	*t;

	if (!storage)
		storage = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(storage), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		t = ft_strjoin(storage, buffer);
		free(storage);
		storage = t;
		if (!storage)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (storage);
}
