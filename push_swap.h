#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# include <stdlib.h>
# include <unistd.h>

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
void	move_to_top_b(t_stack **b, int pos, int size);

#endif