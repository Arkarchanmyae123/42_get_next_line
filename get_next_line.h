/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan-my <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:45:38 by achan-my          #+#    #+#             */
/*   Updated: 2025/11/06 00:16:36 by achan-my         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>  
# include <stdio.h>  

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char			*get_next_line(int fd);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin_and_free(char *left_str, char *buff);
void			*ft_memcpy(void *dest, const void *src, size_t n);
#endif
