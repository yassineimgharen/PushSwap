/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:53:06 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/18 13:49:31 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

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