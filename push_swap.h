/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:30:49 by wcaetano          #+#    #+#             */
/*   Updated: 2023/03/12 17:48:10 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MIN -1
# define MAX 1

# include "libft/libft.h"

int		ft_size_tab(t_list *stack);
int		*get_int_lst(char **argv, int argc);
int		get_int(t_list *node);
void	*pop_back(t_list **stack);
void	*pop_front(t_list **stack);
void	swap(t_list **stack);
void	push(t_list **src, t_list **dst, char *msg);
void	rotate(t_list **stack, char *msg);
void	rrotate(t_list **stack);
void	binary_radix_sort(t_list **stack_a, t_list **stack_b, int size);
t_list	*fill_stack(t_list **stack, int *lst, int size);
int		is_ordered(t_list *stack);
t_list	*parse_lst(int *tmp, int *lst, t_list *stack, int size);
#endif
