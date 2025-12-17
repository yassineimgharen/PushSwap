/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:30:01 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/16 13:30:48 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    ft_putstr_fd("pa\n", 1);
}

void    pb(t_stack **a, t_stack **b)
{
    push(a, b);
    ft_putstr_fd("pb\n", 1);
}