/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:30:46 by yaimghar          #+#    #+#             */
/*   Updated: 2025/12/18 10:30:13 by yaimghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tessaadi <tessaadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:54:36 by tessaadi          #+#    #+#             */
/*   Updated: 2025/12/08 04:52:10 by tessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include "libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strdup( const char *source );
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

typedef struct s_stack
{
	int             value;
	int			 cost_a;
	int			 cost_b;
	struct s_stack  *next;
}   t_stack;

t_stack	*stack_new(int value);
void   	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
void    free_stack(t_stack **stack);

void	ft_error(void);
int		is_valid_number(char *str);
long	ft_atol(const char *ptr);
int		has_duplicate(t_stack *stack, int num);


void    free_split(char **split);
int		is_sorted(t_stack *stack);

void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);

void    sort_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_big(t_stack **a, t_stack **b);

void	move_to_top_a(t_stack **a, int pos, int size);

// rotate_ab_push_to_a.c
void	ft_rotate_a(t_stack **a, t_stack *node);
void	ft_rotate_b(t_stack **b, t_stack *node);
void	ft_push_to_a(t_stack **a, t_stack **b, t_stack *node);

#endif