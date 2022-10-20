/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:42:54 by wcaetano          #+#    #+#             */
/*   Updated: 2022/10/01 16:54:13 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size_tab(t_list *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

void	ft_printf_stacks(t_list *stack_a, t_list *stack_b)
{
	static int	size_a;
	static int	size_b;
	int			num;

	size_a = ft_size_tab(stack_a);
	size_b = ft_size_tab(stack_b);
	while (size_a || size_b)
	{
		if (size_a >= size_b)
		{
			num = *((int *)(stack_a->content));
			ft_printf("\e[0;32m%p %d", stack_a->content, num);
			stack_a = stack_a->next;
			size_a--;
		}
		else
			ft_printf("\e[0;32m                  ");
		ft_printf(" | ");
		if (size_b >= size_a + 1)
		{
			num = *((int *)(stack_a->content));
			ft_printf("\e[0;32m%s %d", stack_b->content, num);
			stack_b = stack_b->next;
			size_b--;
		}
		ft_printf("\n");
	}
	ft_printf("               ---   ---\n                a  |  b\e[0m\n");
}
