/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:27:00 by oessmiri          #+#    #+#             */
/*   Updated: 2024/12/01 15:14:40 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strdup(const char *s);
int		ft_strlen(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*read_file(int fd, char *storage);
char	*extract_line(char *storage);
char	*update_storage(char *storage);

#endif
