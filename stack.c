/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:30:55 by wcaetano          #+#    #+#             */
/*   Updated: 2023/03/14 03:15:31 by wcaetano         ###   ########.fr       */
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
	t_list	*prev;
	t_list	*p;

	p = *stack;
	if (stack && *stack)
	{
		if (!p->next)
			return (pop_front(stack));
		while (p->next)
		{
			prev = p;
			p = p->next;
		}
		tmp = p->content;
		get_int(tmp);
		free(p);
		prev->next = NULL;
		return (tmp);
	}
	return (NULL);
}

int	get_int(t_list *node)
{
	return (*((int *)(node->content)));
}
