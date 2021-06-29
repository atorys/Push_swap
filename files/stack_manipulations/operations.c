#include "../../push_swap.h"

/**
 * swap first two elements at the top of stack A
 * @example before	:	[3]	[2]	1
 * @example after	:	[2]	[3]	1
 * @param  A : given stack
 */
void	swap_s(t_stack **a)
{
	t_stack	*second;

	second = (*a)->next;
	if (*a && (*a)->next)
	{
		(*a)->prev = second;
		(*a)->next = second->next;
		second->prev = NULL;
		if (second->next)
			second->next->prev = *a;
		second->next = *a;
		*a = second;
	}
}

/**
 * first element of stack A becomes last one.
 * @example before	:  [3]	2	1
 * @example after	:	2	1  [3]
 * @param A : given stack
 */
void	rotate_s(t_stack **a)
{
	t_stack	*last;

	last = *a;
	if (*a && (*a)->next)
	{
		*a = (*a)->next;
		while (last->next != NULL)
			last = last->next;
		last->next = (*a)->prev;
		last->next->next = NULL;
		last->next->prev = last;
		(*a)->prev = NULL;
	}
}

/**
 * last element of stack A becomes first one.
 * @example before	:	3	2  [1]
 * @example after	:  [1]	3	2
 * @param A : given stack
 */
void	reverse_rotate_s(t_stack **a)
{
	t_stack	*last;

	if (!(*a))
		return ;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = *a;
	(*a)->prev = last;
	*a = (*a)->prev;
	last->prev->next = NULL;
	last->prev = NULL;
}

/**
 * take first element at the top of "src" and put at the top of "dest"
 * @example push a : B->A
 * @example A | 2 1 ---> 7 2 1 |
 * @example B | 7 5 6 ---> 5 6 |  @example
 * @example push b : A->B
 * @example A | 2 1 ---> 1 |
 * @example B | 7 5 6 ---> 2 7 5 6|
 * @param src: stack source
 * @param dest: stack destination
 */
void	push_s(t_stack **src, t_stack **dest)
{
	if (!(*src))
		return ;
	if (!(*dest))
	{
		*dest = *src;
		*src = (*src)->next;
		if (*src)
			(*src)->prev = NULL;
		(*dest)->next = NULL;
	}
	else
	{
		(*dest)->prev = *src;
		*src = (*src)->next;
		if (*src)
			(*src)->prev = NULL;
		(*dest)->prev->next = *dest;
		*dest = (*dest)->prev;
	}
	(*dest)->prev = NULL;
}
