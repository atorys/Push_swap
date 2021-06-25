#include "../push_swap.h"

/**
 * swap first two elements at the top of stack A
 * before	:	[3]	[2]	1
 * after	:	[2]	[3]	1
 * @param a
 */
void	swap_s(t_stack **a)
{
	t_stack *second;

	second = (*a)->next;
	if (*a && (*a)->next)
	{
		(*a)->prev = second;
		(*a)->next = second->next;
		second->prev = NULL;
		second->next->prev = *a;
		second->next = *a;
		*a = second;
	}
}

/**
 * first element of stack A becomes last one.
 * before	:  [3]	2	1
 * after	:	2	1  [3]
 * @param A : given stack
 */
void	rotate_s(t_stack **a)
{
	t_stack *last;

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
 * before	:	3	2  [1]
 * after	:  [1]	3	2
 * @param A : given stack
 */
void	reverse_rotate_s(t_stack **a)
{
	t_stack *last;

	last = *a;
	if (*a)
	{
		while (last->next != NULL)
			last = last->next; /** find last elem*/
		last->next = *a;	/** link it with first one*/
		(*a)->prev = last;	/** put last before first in stack*/
		*a = (*a)->prev;	/** move head pointer to previous*/
		last->prev->next = NULL;	/** remove link from last element*/
		last->prev = NULL;	/** remove link to pre-last elem from head*/
	}
}

void	push_s(t_stack **src, t_stack **dest)
{
	if (*src)
	{
		if (!(*dest))
			*dest = *src;
		else
		{
			(*dest)->prev = *src;
			*dest = (*dest)->prev;
		}
		*src = (*src)->next;
		(*src)->prev = NULL;
	}
}