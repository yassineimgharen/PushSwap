/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:29:49 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/19 09:39:18 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *a)
{
	t_stack	*tmp;

	int (min_pos), (min_value), (pos);
	tmp = a;
	pos = 0;
	min_pos = 0;
	min_value = tmp->value;
	while (a)
	{
		if (a->value < min_value)
		{
			min_value = a->value;
			min_pos = pos;
		}
		pos++;
		a = a->next;
	}
	return (min_pos);
}
