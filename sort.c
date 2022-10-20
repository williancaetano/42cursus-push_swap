/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:53:29 by wcaetano          #+#    #+#             */
/*   Updated: 2022/10/20 19:00:35 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_edge_value(t_list *stack_a, char min_max)
{
	int	num;
	int tmp;

	num = get_int(stack_a);
	while(stack_a)
	{
		tmp = get_int(stack_a);
		if (min_max == MIN)
		{
			if (tmp < num)
				num = tmp;
		}
		else if (min_max == MAX)
		{
			if (tmp > num)
				num = tmp;
		}
		stack_a = stack_a->next;
	}
	return num;
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

int msb_one(unsigned num, unsigned slack)
{
	int	i;

	i = 0;
	num += slack;
	while (num)
	{
		num >>= 1;
		i++;
	}
	return (i);
}

void	binary_radix_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int			places;
	int			min;
	int			operations;
	int			current_place;
	unsigned	slack;
	unsigned	num;

	slack = 0;
	current_place = 0;
	min = find_edge_value(*stack_a, MIN);
	if (min < 0)
		slack = -min;
	places = msb_one(find_edge_value(*stack_a, MAX), slack);

	while (places--)
	{
		operations = 0;
		if (is_ordered(*stack_a))
			return ;
		while (operations < size)
		{
			num = ((unsigned) get_int(*stack_a)) + slack;
			if ((num >> current_place) & 1)
			{
				ft_printf("pb\n");
				push(stack_a, stack_b);
			}
			else
			{
				ft_printf("ra\n");
				rotate(stack_a);
			}
			operations++;
		}
		operations = ft_lstsize(*stack_b);
		while(operations--)
		{
			ft_printf("pa\n");
			push(stack_b, stack_a);	
		}
		current_place++;
	}
}
