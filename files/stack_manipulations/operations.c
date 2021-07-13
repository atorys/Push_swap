#include "includes/push_swap.h"

void	add_cmd(t_info **process, char *operation)
{
	t_cmd	*new;

	if (!operation)
		return ;
	new = malloc(sizeof(t_cmd));
	if (!new)
		error_case(MALLOCERROR, -1);
	new->command = operation;
	new->next = NULL;
	new->prev = NULL;
	if (!(*process)->operations)
	{
		(*process)->operations = new;
		(*process)->last_op = new;
		return ;
	}
	(*process)->last_op->next = new;
	new->prev = (*process)->last_op;
	(*process)->last_op = new;
}

/**
 * swap first two elements at the top of stack A
 * @example before	:	[3]	[2]	1
 * @example after	:	[2]	[3]	1
 * @param  A : given stack
 */
void	swap_s(t_stack **a, t_info **process, char *operation)
{
	t_stack	*second;

	second = (*a)->next;
	if (*a && (*a)->next)
	{
		(*a)->next = second->next;
		second->next = *a;
		*a = second;
		add_cmd(process, operation);
		indexing(a);
	}
}

/**
 * first element of stack A becomes last one.
 * @example before	:  [3]	2	1
 * @example after	:	2	1  [3]
 * @param A : given stack
 */
void	rotate_s(t_stack **a, t_info **process, char *operation)
{
	t_stack	*last;

	last = *a;
	if (*a && (*a)->next)
	{
		while (last->next != NULL)
			last = last->next;
		last->next = (*a);
		*a = (*a)->next;
		last->next->next = NULL;
		add_cmd(process, operation);
		indexing(a);
	}
}

/**
 * last element of stack A becomes first one.
 * @example before	:	3	2  [1]
 * @example after	:  [1]	3	2
 * @param A : given stack
 */
void	reverse_rotate_s(t_stack **a, t_info **process, char *operation)
{
	t_stack	*last;
	t_stack	*prelast;

	if (!(*a) || !(*a)->next)
		return ;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	prelast = *a;
	while (prelast->next != last)
		prelast = prelast->next;
	prelast->next = NULL;
	last->next = *a;
	*a = last;
	add_cmd(process, operation);
	indexing(a);
}

/**
 * take first element at the top of "src" and put at the top of "dest"
 * @example push a : B->A
 * @example A | 2 1 ---> 7 2 1 |
 * @example B | 7 5 6 ---> 5 6 |
 * @example push b : A->B
 * @example A | 2 1 ---> 1 |
 * @example B | 7 5 6 ---> 2 7 5 6|
 * @param src: stack source
 * @param dest: stack destination
 */
void	push_s(t_stack **src, t_stack **dest, t_info **process, char *operation)
{
	t_stack	*moved;

	if (!(*src))
		return ;
	if (!(*dest))
	{
		*dest = *src;
		*src = (*src)->next;
		(*dest)->next = NULL;
	}
	else
	{
		moved = *src;
		*src = (*src)->next;
		moved->next = *dest;
		*dest = moved;
	}
	add_cmd(process, operation);
	indexing(src);
	indexing(dest);
}
