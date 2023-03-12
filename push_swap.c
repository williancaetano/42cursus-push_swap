/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:01:41 by wcaetano          #+#    #+#             */
/*   Updated: 2023/03/12 16:14:05 by wcaetano         ###   ########.fr       */
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

int	ft_isnumber(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	*get_int_lst(char **argv, int argc)
{
	int		i;
	int		*lst;

	i = 0;
	lst = malloc((argc - 1) * sizeof(*lst));
	while (i < argc - 1)
	{
		if (!ft_isnumber(argv[i + 1]))
		{
			free(lst);
			return (NULL);
		}
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
		write(1, "ERROR\n", 6);
		return (0);
	}
	lst = get_int_lst(argv, argc);
	if (!lst)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	fill_stack(&stack_a, lst, argc - 1);
	binary_radix_sort(&stack_a, &stack_b, argc - 1);
	ft_lstclear(&stack_a, dummy);
	ft_lstclear(&stack_b, dummy);
	free(lst);
}
