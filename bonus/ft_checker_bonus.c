/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:28:40 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/18 13:46:01 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

static void	ft_main_part_2(char *line, t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_strlen(line);
	if (!ft_strncmp(line, "sa\n", len))
		sa(*stack_a);
	else if (!ft_strncmp(line, "sb\n", len))
		sb(*stack_b);
	else if (!ft_strncmp(line, "ss\n", len))
		ss(*stack_a, *stack_b);
	else if (!ft_strncmp(line, "pa\n", len))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(line, "pb\n", len))
		pb(stack_a, stack_b);
	else if (!ft_strncmp(line, "ra\n", len))
		ra(stack_a);
	else if (!ft_strncmp(line, "rb\n", len))
		rb(stack_b);
	else if (!ft_strncmp(line, "rr\n", len))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(line, "rra\n", len))
		rra(stack_a);
	else if (!ft_strncmp(line, "rrb\n", len))
		rrb(stack_b);
	else if (!ft_strncmp(line, "rrr\n", len))
		rrr(stack_a, stack_b);
}

int	ft_is_valid_instruction(char *s)
{
	int	len;

	len = ft_strlen(s);
	return (!ft_strncmp(s, "sa\n", len) || !ft_strncmp(s, "sb\n", len)
		|| !ft_strncmp(s, "ss\n", len) || !ft_strncmp(s, "pa\n", len)
		|| !ft_strncmp(s, "pb\n", len) || !ft_strncmp(s, "ra\n", len)
		|| !ft_strncmp(s, "rb\n", len) || !ft_strncmp(s, "rr\n", len)
		|| !ft_strncmp(s, "rra\n", len) || !ft_strncmp(s, "rrb\n", len)
		|| !ft_strncmp(s, "rrr\n", len));
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

int	main(int count, char **argv)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (count < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	parse_args(count, argv, &stack_a);
	line = get_next_line(0);
	while (line)
	{
		if (!ft_is_valid_instruction(line))
		 return (free_stack(&stack_a), free(line), ft_error(), 1);
		ft_main_part_2(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}