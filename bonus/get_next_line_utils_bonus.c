/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:14:22 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/19 09:46:57 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

char	*ft_strdup(const char *source)
{
	int		i;
	int		srclength;
	char	*tab;

	srclength = 0;
	while (source[srclength])
		srclength++;
	tab = malloc(sizeof(char) * (srclength + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (srclength != 0)
	{
		tab[i] = source[i];
		i++;
		srclength--;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	int (sOneLen), (sTwoLen), (i), (start);
	if (!s1 || !s2)
		return (NULL);
	sOneLen = ft_strlen(s1);
	sTwoLen = ft_strlen(s2);
	str = malloc(sizeof(char) * (sOneLen + sTwoLen + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < sOneLen)
	{
		str[i] = s1[i];
		i++;
	}
	start = 0;
	while (start < sTwoLen)
	{
		str[i + start] = s2[start];
		start++;
	}
	str[i + start] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slength;
	size_t	i;

	if (!s)
		return (NULL);
	slength = ft_strlen(s);
	if (len > (slength - start))
		len = slength - start;
	if (start >= slength)
		return (ft_strdup(""));
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
