/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:42:53 by yaimghar          #+#    #+#             */
/*   Updated: 2025/11/29 13:27:04 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// 9lb joj lwlin 
void    sa(t_stack *a)
{
    swap(a);
    ft_putstr_fd("sa\n", 1);
}

void    sb(t_stack *b)
{
    swap(b);
    ft_putstr_fd("sb\n", 1);
}

void    ss(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
    ft_putstr_fd("ss\n", 1);
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

// lwla f b become lwla f a
void    pa(t_stack **a, t_stack **b)
{
    push(b, a);
    ft_putstr_fd("pa\n", 1);
}

void    pb(t_stack **a, t_stack **b)
{
    push(a, b);
    ft_putstr_fd("pb\n", 1);
}

// lwla becomes last
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

// last mn a becomes lwl mn a
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