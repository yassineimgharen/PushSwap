/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_operations.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:54:43 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/18 11:55:13 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

static void    reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *second_last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    last = *stack;
    second_last = *stack;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    last->next = *stack;
    *stack = last;
    second_last->next = NULL;
}

void    rra(t_stack **a)
{
    reverse_rotate(a);
    ft_putstr_fd("rra\n", 1);
}

void    rrb(t_stack **b)
{
    reverse_rotate(b);
    ft_putstr_fd("rrb\n", 1);
}

void    rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_putstr_fd("rrr\n", 1);
}