/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:08:27 by yaimghar          #+#    #+#             */
/*   Updated: 2025/11/27 15:13:34 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	is_separator(const char c, char charset)
{
	return (c == charset);
}

int	count_words(const char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_separator(str[i], charset))
			i++;
		if (str[i] != '\0' && !is_separator(str[i], charset))
		{
			count++;
			while (str[i] != '\0' && !is_separator(str[i], charset))
				i++;
		}
	}
	return (count);
}

char	*get_word(const char *str, char charset, int *index)
{
	int		start;
	int		len;
	int		j;
	char	*word;

	start = *index;
	len = 0;
	j = 0;
	while (str[*index] != '\0' && !is_separator(str[*index], charset))
	{
		(*index)++;
		len++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	while (j < len)
	{
		word[j] = str[start + j];
		j++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	char	**tab;

	i = 0;
	j = 0;
	words = count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && is_separator(s[i], c))
			i++;
		if (s[i] != '\0' && !is_separator(s[i], c))
		{
			tab[j] = get_word(s, c, &i);
			j++;
		}
	}
	tab[j] = 0;
	return (tab);
}
