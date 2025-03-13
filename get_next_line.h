/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:39:25 by luferna3          #+#    #+#             */
/*   Updated: 2025/03/12 03:10:40 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char *s, int start, int len);
char	*read_buffer(int fd, char *storage);
char	*add_line(char *storage);
char	*clean(char *storage);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strrchr(char *s, int c);

#endif