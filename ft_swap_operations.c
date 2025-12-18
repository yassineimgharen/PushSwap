/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:51:39 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/18 11:52:18 by yaimghar         ###   ########.fr       */
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