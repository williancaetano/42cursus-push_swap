/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:50:06 by wcaetano          #+#    #+#             */
/*   Updated: 2022/10/20 18:18:41 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa sb
void	swap(t_list **stack)
{
	void	*tmp1;
	void	*tmp2;

	tmp1 = pop_front(stack);
	if (!tmp1)
	{
		ft_printf("Empty! ");
		return ;
	}
	tmp2 = pop_front(stack);
	if (!tmp2)
	{
		ft_lstadd_front(stack, tmp1);
		ft_printf("Only 1 item! ");
		return ;
	}
	ft_lstadd_front(stack, ft_lstnew(tmp2));
	ft_lstadd_front(stack, ft_lstnew(tmp1));
}

//pa pb
void	push(t_list **src, t_list **dst)
{
	void	*tmp;

	tmp = pop_front(src);
	if (!tmp)
	{
		ft_printf("Empty! ");
		return ;
	}
	ft_lstadd_front(dst, ft_lstnew(tmp));
}

// ra rb
void	rotate(t_list **stack)
{
	void	*tmp;

	tmp = pop_front(stack);
	if (!tmp)
	{
		ft_printf("Empty! ");
		return ;
	}
	ft_lstadd_back(stack, ft_lstnew(tmp));
}

//rra rrb
void	rrotate(t_list **stack)
{
	void	*tmp;

	tmp = pop_back(stack);
	if (!tmp)
	{
		ft_printf("Empty! ");
		return ;
	}
	ft_lstadd_front(stack, ft_lstnew(tmp));
}
