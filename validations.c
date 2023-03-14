/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 02:22:47 by wcaetano          #+#    #+#             */
/*   Updated: 2023/03/14 03:15:16 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_repeat(int *lst, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (lst[i] == lst[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_overflow(char **str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i])
	{
		tmp = ft_itoa(ft_atoi(str[i]));
		if (ft_strncmp(tmp, str[i], ft_strlen(str[i])) != 0)
		{
			free(tmp);
			return (0);
		}
		i++;
	}
	free(tmp);
	return (1);
}
