/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:50:06 by wcaetano          #+#    #+#             */
/*   Updated: 2023/03/14 03:14:11 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa sb
void	swap(t_list **stack, char *msg)
{
	void	*tmp1;
	void	*tmp2;

	tmp1 = pop_front(stack);
	if (!tmp1)
		return ;
	tmp2 = pop_front(stack);
	if (!tmp2)
	{
		ft_lstadd_front(stack, tmp1);
		return ;
	}
	ft_lstadd_front(stack, ft_lstnew(tmp2));
	ft_lstadd_front(stack, ft_lstnew(tmp1));
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
}

//pa pb
void	push(t_list **src, t_list **dst, char *msg)
{
	void	*tmp;

	tmp = pop_front(src);
	if (!tmp)
		return ;
	ft_lstadd_front(dst, ft_lstnew(tmp));
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
}

// ra rb
void	rotate(t_list **stack, char *msg)
{
	void	*tmp;

	tmp = pop_front(stack);
	if (!tmp)
		return ;
	ft_lstadd_back(stack, ft_lstnew(tmp));
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
}

//rra rrb
void	rrotate(t_list **stack, char *msg)
{
	t_list	*last;
	t_list	*prev;
	t_list	*current;

	current = *stack;
	prev = NULL;
	last = NULL;
	if (!current || !current->next)
		return ;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	last = current;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
}
