/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:49:42 by yaimghar          #+#    #+#             */
/*   Updated: 2025/11/27 15:13:50 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup( const char *source )
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
