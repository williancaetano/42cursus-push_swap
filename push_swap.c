/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:01:41 by wcaetano          #+#    #+#             */
/*   Updated: 2022/10/20 19:00:21 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dummy(void *tmp)
{
	if (tmp)
		return ;
	else
		return ;
}

int	*get_int_lst(char **argv, int argc)
{
	int		i;
	int		*lst;

	i = 0;
	lst = malloc((argc - 1) * sizeof(*lst));
	while (i < argc - 1)
	{
		lst[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (lst);
}

t_list	*fill_stack(t_list **stack, int *lst, int size)
{
	int		i;
	t_list	*node;

	i = 0;
	while (i < size)
	{
		node = ft_lstnew(lst + i);
		if (!node)
			return (NULL);
		ft_lstadd_back(stack, node);
		i++;
	}
	return (*stack);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*lst;

	if (argc < 2)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	lst = get_int_lst(argv, argc);
	if (!lst)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	stack_a = NULL;
	stack_b = NULL;
	fill_stack(&stack_a, lst, argc - 1);
	binary_radix_sort(&stack_a, &stack_b, argc - 1);
	ft_lstclear(&stack_a, dummy);
	ft_lstclear(&stack_b, dummy);
	free(lst);
}
