/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:22:19 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/18 10:38:41 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

static char	*fill_buffer(int fd, char *buf, char *remain_from_line)
{
	int		full_buffer;
	char	*tmp;

	full_buffer = 1;
	while (full_buffer > 0)
	{
		full_buffer = read(fd, buf, BUFFER_SIZE);
		if (full_buffer == -1)
		{
			free(remain_from_line);
			return (NULL);
		}
		else if (full_buffer == 0)
			break ;
		buf[full_buffer] = '\0';
		if (!remain_from_line)
			remain_from_line = ft_strdup("");
		tmp = remain_from_line;
		remain_from_line = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(remain_from_line, '\n'))
			break ;
	}
	return (remain_from_line);
}

static char	*extract_remain(char *whole_line)
{
	int		i;
	char	*remain;

	i = 0;
	while (whole_line[i] != '\n' && whole_line[i] != '\0')
		i++;
	if (whole_line[i] == '\0' || whole_line[i + 1] == '\0')
		return (NULL);
	remain = ft_substr(whole_line, i + 1, ft_strlen(whole_line) - i);
	whole_line[i + 1] = '\0';
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*remain_from_line;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = fill_buffer(fd, buf, remain_from_line);
	if (!line)
		return (free(buf), NULL);
	free(buf);
	buf = NULL;
	remain_from_line = extract_remain(line);
	return (line);
}
