/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:03:42 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/04 16:04:39 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_to_top_b(t_stack **b, int pos, int size)
{
    if (pos <= size / 2)
    {
        while (pos > 0)
        {
            rb(b);
            pos--;
        }
    }
    else
    {
        while (pos < size)
        {
            rrb(b);
            pos++;
        }
    }
}
void	move_to_top_a(t_stack **a, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < size)
			rra(a);
	}
}
