/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:52:00 by mlapique          #+#    #+#             */
/*   Updated: 2024/03/18 15:35:50 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_last_index(t_stack *stack_a)
{
	t_stack	*temp;
	int		max;

	temp = stack_a;
	max = 0;
	while (temp)
	{
		temp = temp->next;
		max++;
	}
	return (max);
}

void	usable_suposed_place(t_stack *stack)
{
	int		i;
	t_stack	*temp;
	t_stack	*higher;

	higher = stack;
	temp = stack;
	i = get_last_index(stack);
	while (i > 0)
	{
		while (temp)
		{
			if ((temp->integer > higher->integer && temp->suposed_place == -1)
				|| higher->suposed_place != -1)
				higher = temp;
			temp = temp->next;
		}
		higher->suposed_place = i - 1;
		i--;
		temp = stack;
		higher = stack;
	}
}

void	ini_first_stack(char *argv[], t_stack *stack_a)
{
	int	nb;

	nb = ft_atoi(argv[0]);
	stack_a->integer = nb;
	stack_a->index = 1;
	stack_a->suposed_place_temp = -1;
	stack_a->next = NULL;
	stack_a->suposed_place = -1;
	stack_a->binary = NULL;
}

int	ini_stack(char *argv[], t_stack *stack_a)
{
	int		i;
	int		nb;
	t_stack	*new_chain;

	i = 1;
	ini_first_stack(argv, stack_a);
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		new_chain = lstnew(nb);
		if (new_chain == NULL)
			return (-1);
		new_chain->index = i + 1;
		ft_lstadd(stack_a, new_chain);
		i++;
	}
	if (i == 1)
		return (free_argv(argv), -1);
	usable_suposed_place(stack_a);
	if (transform_to_binary(stack_a) == -1)
		return (error(MALLOC));
	return (0);
}
