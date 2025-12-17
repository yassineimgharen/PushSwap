/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 20:00:29 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/17 20:12:40 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exit_error(t_stack **a, char **split)
{
	free_stack(a);
	if (split)
		free_split(split);
	ft_error();
}

void    add_to_stack(t_stack **a, char *str, char **split)
{
    long num;
    if (!is_valid_number(str))
        exit_error(a, split);
    num = ft_atol(str);
    if (num > 2147483647 || num < -2147483648)
    {
        exit_error(a, split);
    }
    if (has_duplicate(*a, (int)num))
    {
        exit_error(a, split);
    }
    stack_add_back(a, stack_new((int)num));
}


static void parse_args(int argc, char **argv, t_stack **a)
{
    int     i;
    char    **split;
    if (argc == 2)
    {
        i = 0;
        split = ft_split(argv[1], ' ');
        while (split[i])
        {
            add_to_stack(a, split[i], split);
            i++;
        }
        free_split(split);
    }
    else
    {
        i = 1;
        while (i < argc)
        {
            add_to_stack(a, argv[i], NULL);
            i++;
        }
    }
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (argc == 1)
        return (0);
    if (argc == 2 && argv[1][0] == '\0')
        exit_error(&a, NULL);
    parse_args(argc, argv, &a);
    if (is_sorted(a))
    {
        free_stack(&a);
        return (0);
    }
    sort_stack(&a, &b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}