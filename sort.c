/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:17:07 by wcaetano          #+#    #+#             */
/*   Updated: 2023/03/14 03:21:47 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	int	nums[3];

	nums[0] = get_int(*stack_a);
	nums[1] = get_int((*stack_a)->next);
	nums[2] = get_int((*stack_a)->next->next);
	if (nums[0] > nums[1] && nums[0] < nums[2] && nums[1] < nums[2])
		swap(stack_a, "sa");
	else if (nums[0] > nums[1] && nums[0] > nums[2] && nums[1] > nums[2])
	{
		swap(stack_a, "sa");
		rrotate(stack_a, "rra");
	}
	else if (nums[0] > nums[1] && nums[0] > nums[2] && nums[1] < nums[2])
		rotate(stack_a, "ra");
	else if (nums[0] < nums[1] && nums[0] < nums[2] && nums[1] > nums[2])
	{
		swap(stack_a, "sa");
		rotate(stack_a, "ra");
	}
	else if (nums[0] < nums[1] && nums[0] > nums[2] && nums[1] > nums[2])
		rrotate(stack_a, "rra");
}

void	push_smallest(t_list **stack_a, t_list **stack_b, int i)
{
	int		pos;
	int		smallest;
	t_list	*p;

	smallest = get_int(*stack_a);
	p = *stack_a;
	while (p)
	{
		if (get_int(p) < smallest)
		{
			smallest = get_int(p);
			pos = i;
		}
		p = p->next;
		i++;
	}
	while (smallest != get_int(*stack_a))
	{
		if (pos < ft_lstsize(*stack_a) / 2)
			rotate(stack_a, "ra");
		else
			rrotate(stack_a, "rra");
	}
	push(stack_a, stack_b, "pb");
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	push_smallest(stack_a, stack_b, 0);
	ft_lstsize(*stack_a);
	ft_lstsize(*stack_a);
	sort_three(stack_a);
	push(stack_b, stack_a, "pa");
}

void	until_five_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 4)
	{
		sort_four(stack_a, stack_b);
		return ;
	}
	while (ft_lstsize(*stack_a) > 3)
		push_smallest(stack_a, stack_b, 0);
	sort_three(stack_a);
	while (*stack_b)
		push(stack_b, stack_a, "pa");
}
