/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:07:11 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/19 09:30:02 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target(int num, t_stack *a)
{
	int		i;
	int		max;
	int		target_index;
	t_stack	*acc;

	target_index = -1;
	i = 0;
	max = 2147483647;
	acc = a;
	while (acc)
	{
		if (num < acc->value && acc->value < max)
		{
			max = acc->value;
			target_index = i;
		}
		i++;
		acc = acc->next;
	}
	if (target_index == -1)
		return (find_min_pos(a));
	return (target_index);
}

void	assign_cost(t_stack *a, t_stack *b)
{
	int	i;
	int	target;
	int	size_a;
	int	size_b;

	i = 0;
	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		target = get_target(b->value, a);
		if (target <= (size_a / 2))
			b->cost_a = target;
		else
			b->cost_a = -(size_a - target);
		if (i <= (size_b / 2))
			b->cost_b = i;
		else
			b->cost_b = -(size_b - i);
		i++;
		b = b->next;
	}
}

int	ft_compute_cost(int cost_a, int cost_b)
{
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
	{
		if (ft_abs(cost_a) > ft_abs(cost_b))
			return (ft_abs(cost_a));
		else
			return (ft_abs(cost_b));
	}
	else
		return (ft_abs(cost_a) + ft_abs(cost_b));
}

t_stack	*get_min_cost(t_stack *b)
{
	int		max;
	int		cost;
	t_stack	*node;

	max = 2147483647;
	while (b)
	{
		cost = ft_compute_cost(b->cost_a, b->cost_b);
		if (cost < max)
		{
			node = b;
			max = cost;
		}
		b = b->next;
	}
	return (node);
}

void	sort_big(t_stack **a, t_stack **b)
{
	t_stack	*node;
	int		min_pos;

	while (stack_size(*a) > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
	{
		assign_cost(*a, *b);
		node = get_min_cost(*b);
		ft_push_to_a(a, b, node);
	}
	min_pos = find_min_pos(*a);
	move_to_top_a(a, min_pos, stack_size(*a));
}
