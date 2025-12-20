/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab_push_to_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:12:50 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/19 09:23:20 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stack **a, t_stack *node)
{
	while (node->cost_a > 0)
	{
		ra(a);
		node->cost_a--;
	}
	while (node->cost_a < 0)
	{
		rra(a);
		node->cost_a++;
	}
}

void	ft_rotate_b(t_stack **b, t_stack *node)
{
	while (node->cost_b > 0)
	{
		rb(b);
		node->cost_b--;
	}
	while (node->cost_b < 0)
	{
		rrb(b);
		node->cost_b++;
	}
}

void	ft_push_to_a(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		rr(a, b);
		node->cost_a--;
		node->cost_b--;
	}
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		rrr(a, b);
		node->cost_a++;
		node->cost_b++;
	}
	ft_rotate_a(a, node);
	ft_rotate_b(b, node);
	pa(a, b);
}
