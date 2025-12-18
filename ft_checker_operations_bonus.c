/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_operations_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:00:33 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/18 11:02:24 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

static void    swap(t_stack *stack)
{
    int temp;
    if (stack && stack->next)
    {
        temp = stack->value;
        stack->value = stack->next->value;
        stack->next->value = temp;
    }
}

void    sa(t_stack *a)
{
    swap(a);
}

void    sb(t_stack *b)
{
    swap(b);
}

void    ss(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
}


static void    push(t_stack **src, t_stack **dst)
{
    t_stack *temp;

    if (!src || !*src)
        return ;
    temp = *src;
    *src = (*src)->next;
    temp->next = *dst;
    *dst = temp;
}

void    pa(t_stack **a, t_stack **b)
{
    push(b, a);
}

void    pb(t_stack **a, t_stack **b)
{
    push(a, b);
}

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
}

void    rb(t_stack **b)
{
    rotate(b);
}

void    rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
}

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
}

void    rrb(t_stack **b)
{
    reverse_rotate(b);
}

void    rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
}