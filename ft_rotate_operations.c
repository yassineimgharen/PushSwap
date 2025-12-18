/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:53:48 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/18 11:54:11 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

static void    rotate(t_stack **stack)
{
    t_stack *temp;
    t_stack *last;
    if (!stack || !*stack || !(*stack)->next)
        return ;
    temp = *stack;
    last = *stack;
    *stack = (*stack)->next;
    while (last->next)
        last = last->next;
    last->next = temp;
    temp->next = NULL;
}

void    ra(t_stack **a)
{
    rotate(a);
    ft_putstr_fd("ra\n", 1);
}

void    rb(t_stack **b)
{
    rotate(b);
    ft_putstr_fd("rb\n", 1);
}

void    rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    ft_putstr_fd("rr\n", 1);
}