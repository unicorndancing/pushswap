/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:19:20 by mlapique          #+#    #+#             */
/*   Updated: 2024/03/15 17:10:18 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack->binary);
		free(stack);
		stack = temp;
	}
	stack = NULL;
}

void	free_argv(char *argv[])
{
	int	i;

	i = 0;
	if (argv == NULL)
		return ;
	while (argv[i])
	{
		if (argv[i] != NULL)
			free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
	argv = NULL;
}
