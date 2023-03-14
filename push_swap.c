/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:01:41 by wcaetano          #+#    #+#             */
/*   Updated: 2023/03/14 03:39:32 by wcaetano         ###   ########.fr       */
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

void	init(t_list **stack_a, t_list **stack_b, int **lst, char **argv)
{
	int	argc;

	*stack_a = NULL;
	*stack_b = NULL;
	argc = 0;
	while (argv[argc])
		argc++;
	if (argc == 1)
		exit(0);
	*lst = get_int_lst(argv, argc);
	if (!*lst)
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	if (!check_repeat(*lst, argc - 1) || !check_overflow(argv + 1))
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	fill_stack(stack_a, *lst, argc - 1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*lst;

	init(&stack_a, &stack_b, &lst, argv);
	if (!is_ordered(stack_a))
	{
		if (argc - 1 == 2)
			swap(&stack_a, "sa");
		else if (argc - 1 == 3)
			sort_three(&stack_a);
		else if (argc - 1 == 5 || argc - 1 == 4)
			until_five_sort(&stack_a, &stack_b);
		else
			binary_radix_sort(&stack_a, &stack_b, argc - 1);
	}
	ft_lstclear(&stack_a, dummy);
	ft_lstclear(&stack_b, dummy);
}
