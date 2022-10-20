/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:30:55 by wcaetano          #+#    #+#             */
/*   Updated: 2022/10/01 17:21:36 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*pop_front(t_list **stack)
{
	void	*content;
	t_list	*node;

	if (stack && *stack)
	{
		content = (*stack)->content;
		node = *stack;
		*stack = (*stack)->next;
		free(node);
		return (content);
	}
	return (NULL);
}

void	*pop_back(t_list **stack)
{
	void	*tmp;

	if (stack && *stack)
	{
		if (!(*stack)->next)
			return (pop_front(stack));
		while ((*stack)->next)
		{
			if (!(*stack)->next->next)
			{
				tmp = (*stack)->next->content;
				free((*stack)->next);
				(*stack)->next = NULL;
				return (tmp);
			}
			*stack = (*stack)->next;
		}
	}
	return (NULL);
}

int	get_int(t_list *node)
{
	return (*((int *)(node->content)));
}