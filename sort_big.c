/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:07:11 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/15 19:08:54 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_min_pos(t_stack *a)
{
	t_stack *tmp;
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

// a smaller biger than b or min value in a (index not value)
static int find_target_pos(t_stack *a, int b_value)
{
	t_stack *tmp;
	int (target_index), (value), (pos);
	target_index = 0;
	value = 2147483647;
	pos = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->value > b_value && tmp->value < value)
		{
			value = tmp->value;
			target_index = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	if (value == 2147483647)
		return (find_min_pos(a));
	return (target_index);
}
static int calc_cost(int pos, int size)
{
    if (pos <= size / 2)
        return (pos);
    return (size - pos);
}

static int find_cheapest_pos(t_stack *a, t_stack *b)
{
	int (size_b), (size_a), (pos_b), (cost_b), (cost_a), (min_cost), (cheapest_pos), (total), (target_pos);
	pos_b = 0;
	size_b = stack_size(b);
	size_a = stack_size(a);
	min_cost = 2147483647;
	cheapest_pos = 0;
	while (b)
	{
		cost_b = calc_cost(pos_b, size_b);
		target_pos = find_target_pos(a, b->value);
		cost_a = calc_cost(target_pos, size_a);	
		total = cost_a + cost_b;
		if (total < min_cost)
		{
			min_cost = total;
			cheapest_pos = pos_b;
		}
		pos_b++;
		b = b->next;
	}
	return (cheapest_pos);
}

static void do_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	int (b_pos), (pos), (value), (target_pos);
	value = 0;
	pos = 0;
	b_pos = find_cheapest_pos(*a, *b);
	tmp = *b;
	while (tmp)
	{
		if (pos == b_pos)
		{
			value = tmp->value;
			break ;
		}
		pos++;
		tmp = tmp->next;
	}
	target_pos = find_target_pos(*a, value);
	move_to_top_b(b, b_pos, stack_size(*b));
	move_to_top_a(a, target_pos, stack_size(*a));
	pa(a, b);
}


void	sort_big(t_stack **a, t_stack **b)
{
	int min_pos;
	while (stack_size(*a) > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
		do_cheapest_move(a, b);
	min_pos = find_min_pos(*a);
	move_to_top_a(a, min_pos, stack_size(*a));
}
