/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan-my <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:34:11 by achan-my          #+#    #+#             */
/*   Updated: 2025/11/05 23:56:43 by achan-my         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static	int	read_from_file(int fd, char **leftover)
// {
// 	char	*buffer;
// 	int		bytes_read;

// 	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buffer)
// 		return (-1);
// 	bytes_read = 1;
// 	while (bytes_read > 0)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read == -1)
// 		{
// 			free(buffer);
// 			return (-1);
// 		}
// 		if (bytes_read == 0)
// 			break ;
// 		buffer[bytes_read] = '\0';
// 		*leftover = ft_strjoin_and_free(*leftover, buffer);
// 		if (!*leftover)
// 		{
// 			free(buffer);
// 			return (-1);
// 		}
// 		if (ft_strchr(*leftover, '\n'))
// 			break ;
// 	}
// 	free(buffer);
// 	if (bytes_read == 0 && (*leftover == NULL || **leftover == '\0'))
// 		return (0);
// 	return (1);
// }

static	int	cleanup(char *buffer, int return_value)
{
	free(buffer);
	return (return_value);
}

static	int	read_from_file(int fd, char **leftover)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (cleanup(buffer, -1));
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		*leftover = ft_strjoin_and_free(*leftover, buffer);
		if (!*leftover)
			return (cleanup(buffer, -1));
		if (ft_strchr(*leftover, '\n'))
			break ;
	}
	if (bytes_read == 0 && (*leftover == NULL || **leftover == '\0'))
		return (cleanup(buffer, 0));
	return (cleanup(buffer, 1));
}

// static	char	*cleanup_and_fail(char *line, char *temp, char **leftover)
// {
// 	free(line);
// 	free(temp);
// 	free(*leftover);
// 	*leftover = NULL;
// 	return (NULL);
// }
// static	char	*cleanup_and_succeed(char *line, char *temp,
//char **leftover)
// {
// 	free(*leftover);
// 	*leftover = temp;
// 	if (*leftover && **leftover == '\0')
// 	{
// 		free(*leftover);
// 		*leftover = NULL;
// 	}
// 	return (line);
// }
// char	*extract_line(char **leftover)
// {
// 	char	*line;
// 	char	*temp;
// 	int		i;
// 	i = 0;
// 	while ((*leftover)[i] && (*leftover)[i] != '\n')
// 		i++;
// 	if ((*leftover)[i] == '\n')
// 	{
// 		line = ft_substr(*leftover, 0, i + 1);
// 		temp = ft_strdup(*leftover + i + 1);
// 	}
// 	else
// 	{
// 		line = ft_strdup(*leftover);
// 		temp = NULL;
// 	}
// 	if (!line || ((*leftover)[i] == '\n' && !temp))
// 		return (cleanup_and_fail(line, temp, leftover));
// 	return (cleanup_and_succeed(line, temp, leftover));
// }

static	char	*cleanup2_ext(char *line, char *temp,
	char **leftover, int is_success)
{
	if (is_success)
	{
		free(*leftover);
		*leftover = temp;
		if (*leftover && **leftover == '\0')
		{
			free(*leftover);
			*leftover = NULL;
		}
		return (line);
	}
	else
	{
		free(line);
		free(temp);
		free(*leftover);
		*leftover = NULL;
		return (NULL);
	}
}

char	*extract_line(char **leftover)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	while ((*leftover)[i] && (*leftover)[i] != '\n')
		i++;
	if ((*leftover)[i] == '\n')
	{
		line = ft_substr(*leftover, 0, i + 1);
		temp = ft_strdup(*leftover + i + 1);
	}
	else
	{
		line = ft_strdup(*leftover);
		temp = NULL;
	}
	if (!line || ((*leftover)[i] == '\n' && !temp))
		return (cleanup2_ext(line, temp, leftover, 0));
	return (cleanup2_ext(line, temp, leftover, 1));
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	int			read_status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!leftover || !ft_strchr(leftover, '\n'))
	{
		read_status = read_from_file(fd, &leftover);
		if (read_status <= 0)
		{
			if (leftover)
			{
				line = leftover;
				leftover = NULL;
				return (line);
			}
			return (NULL);
		}
	}
	line = extract_line(&leftover);
	return (line);
}
