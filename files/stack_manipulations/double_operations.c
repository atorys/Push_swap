#include "../../push_swap.h"

/**
 * swap A and swap B at the same time
 * @func swap: void	swap_s(t_stack **a);
 * @param a: given stack A
 * @param b: given stack B
 * @example A | 2 1 3 ---> 1 2 3 |
 * @example B | 7 5 6 ---> 5 7 6 |
 */
void	ss(t_stack **a, t_stack **b, t_info **process)
{
	swap_s(a, process, "ss\n");
	swap_s(b, process, NULL);
}

/**
 * rotate A & B: put first elems to the bottom of both stacks.
 * @func rotate: void	rotate_s(t_stack **a);
 * @param a: given stack A
 * @param b: given stack B
 * @example A | 2 1 3 ---> 1 3 2 |
 * @example B | 7 5 6 ---> 5 6 7 |
 */
void	rr(t_stack **a, t_stack **b, t_info **process)
{
	rotate_s(a, process, "rr\n");
	rotate_s(b, process, NULL);
}

/**
 * rr x2: last elems of both stacks become first one
 * @func rr: void	reverse_rotate_s(t_stack **a);
 * @param a: given stack A
 * @param b: given stack B
 * @example A | 2 1 3 ---> 3 2 1 |
 * @example B | 7 5 6 ---> 6 7 5 |
 */
void	rrr(t_stack **a, t_stack **b, t_info **process)
{
	reverse_rotate_s(a, process, "rrr\n");
	reverse_rotate_s(b, process, NULL);
}
