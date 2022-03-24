/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:36:17 by cbustama          #+#    #+#             */
/*   Updated: 2021/09/20 22:46:47 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>

void	free_and_reset(void *var);
char	*ft_strchr(const char *s, int c);
ssize_t	read_line(char **holder, char **buffer, char **final_line, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char const *s1);
char	*split_line(char **holder);
char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
#endif
