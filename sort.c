/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:32:09 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/14 18:21:47 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && first > third) //231
		ra(a);
	else if (second > first && second > third)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(*a);
}

int	get_min_pos(t_stack *stack)
{
	int		min;
	int		pos;
	int		min_pos;
	t_stack	*tmp;

	tmp = stack;
	min = tmp->value;
	pos = 0;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

void	move_min_to_top(t_stack **a, int pos, int size)
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

static void	sort_small(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	while (stack_size(*a) > 3)
	{
		pos = get_min_pos(*a);
		size = stack_size(*a);
		move_min_to_top(a, pos, size);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(*a);
	}
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_small(a, b);
	else
		sort_big(a, b);
}
