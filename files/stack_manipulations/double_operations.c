#include "../../push_swap.h"

/**
 * swap A and swap B at the same time
 * @func swap: void	swap_s(t_stack **a);
 * @param a: given stack A
 * @param b: given stack B
 * @example A | 2 1 3 ---> 1 2 3 |
 * @example B | 7 5 6 ---> 5 7 6 |
 */
void	ss(t_stack **a, t_stack **b)
{
	swap_s(a);
	swap_s(b);
}

/**
 * rotate A & B: put first elems to the bottom of both stacks.
 * @func rotate: void	rotate_s(t_stack **a);
 * @param a: given stack A
 * @param b: given stack B
 * @example A | 2 1 3 ---> 1 3 2 |
 * @example B | 7 5 6 ---> 5 6 7 |
 */
void	rr(t_stack **a, t_stack **b)
{
	rotate_s(a);
	rotate_s(b);
}

/**
 * rr x2: last elems of both stacks become first one
 * @func rr: void	reverse_rotate_s(t_stack **a);
 * @param a: given stack A
 * @param b: given stack B
 * @example A | 2 1 3 ---> 3 2 1 |
 * @example B | 7 5 6 ---> 6 7 5 |
 */
void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate_s(a);
	reverse_rotate_s(b);
}
