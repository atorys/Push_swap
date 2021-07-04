#include "../../push_swap.h"
#include "../../libft/libft.h"
#include <stdio.h>

void add_cmd(t_info **process, char *operation)
{
	t_cmd	*new;

	if ((*process)->operations && operation[0] == 'p')
	{
		if ((*process)->last_op->command[0] == 'p' && (*process)->last_op->command[1] != operation[1])
		{
			if ((*process)->last_op == (*process)->operations)
			{
				free((*process)->operations);
				(*process)->operations = NULL;
				(*process)->last_op = NULL;
			}
			else
			{
				(*process)->last_op = (*process)->last_op->prev;
				free((*process)->last_op->next);
				(*process)->last_op->next = NULL;
			}
			return ;
		}
	}
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
		(*a)->prev = second;
		(*a)->next = second->next;
		second->prev = NULL;
		if (second->next)
			second->next->prev = *a;
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
		*a = (*a)->next;
		while (last->next != NULL)
			last = last->next;
		last->next = (*a)->prev;
		if (operation[1] == 'a')
			(*process)->tail_a = last->next;
		else
			(*process)->tail_b = last->next;
		last->next->next = NULL;
		last->next->prev = last;
		(*a)->prev = NULL;
		add_cmd(process, operation);
		indexing(a);
	}
	if (operation[1] == 'a')
		(*process)->tail_a = last;
	else
		(*process)->tail_b = last;
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

	if (!(*a))
		return ;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	if (operation[2] == 'a')
		(*process)->tail_a = last->prev;
	else
		(*process)->tail_b = last->prev;
	last->next = *a;
	(*a)->prev = last;
	*a = (*a)->prev;
	last->prev->next = NULL;
	last->prev = NULL;
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
//	if (!(*src))
//		return ;
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
	add_cmd(process, operation);
	indexing(src);
	indexing(dest);
}
