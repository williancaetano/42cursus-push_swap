/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:53:29 by wcaetano          #+#    #+#             */
/*   Updated: 2023/03/12 16:43:11 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_list(t_list *stack, int *lst, int size)
{
	int	i;
	int	j;
	int	min_index;
	int	tmp;

	i = 0;
	while (i < size)
	{
		lst[i] = get_int(stack);
		stack = stack->next;
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i;
		min_index = i;
		while (j < size)
		{
			if (lst[j] < lst[min_index])
				min_index = j;
			j++;
		}
		tmp = lst[i];
		lst[i] = lst[min_index];
		lst[min_index] = tmp;
		i++;
	}
}

void	index_stack(t_list	*stack, int size)
{
	int		*lst;
	int		i;
	int		j;
	t_list	*p;
	int		*tmp;

	lst = malloc(sizeof(int) * size);
	tmp = malloc(sizeof(int) * size);
	if (!lst)
		exit(1);
	fill_list(stack, lst, size);
	i = 0;
	while (i < size)
	{
		p = stack;
		j = 0;
		while (p)
		{
			if (get_int(p) == lst[i])
			{
				tmp[j] = i;
				break ;
			}
			j++;
			p = p->next;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		*((int *)stack->content) = tmp[i++];
		stack = stack->next;
	}
	free(lst);
	free(tmp);
}

int	is_ordered(t_list *stack)
{
	int	last;
	int	actual;

	last = get_int(stack);
	while (stack)
	{
		actual = get_int(stack);
		if (last > actual)
			return (0);
		stack = stack->next;
		last = actual;
	}
	return (1);
}

void	binary_radix_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	operations;
	int	current_place;
	int	b_size;

	index_stack(*stack_a, size);
	current_place = 0;
	while (!is_ordered(*stack_a))
	{
		operations = 0;
		b_size = 0;
		while (operations < size)
		{
			if (((get_int(*stack_a) >> current_place) & 1) == 1)
			{
				write(1, "ra\n", 3);
				rotate(stack_a);
			}
			else
			{
				write(1, "pb\n", 3);
				push(stack_a, stack_b);
				b_size++;
			}
			operations++;
		}
		while (b_size--)
		{
			write(1, "pa\n", 3);
			push(stack_b, stack_a);
		}
		current_place++;
	}
}
