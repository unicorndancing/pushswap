/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_for_a_lot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:31:00 by mlapique          #+#    #+#             */
/*   Updated: 2024/03/14 18:50:57 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	the_sort_stackb(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	nbinstack;

	nbinstack = get_last_index(*stack_b);
	while (nbinstack > 0 && i > 0)
	{
		if ((*stack_b)->binary[i - 1] == '1')
			do_pa(stack_a, stack_b);
		else
		{
			if ((*stack_b)->next != NULL)
				do_rb(stack_b);
		}
		nbinstack--;
	}
}

void	sort_the_end(t_stack **stack_a, t_stack **stack_b)
{
	int	nbinstack;

	nbinstack = get_last_index(*stack_b);
	while (nbinstack > -1)
	{
		do_pa(stack_a, stack_b);
		nbinstack--;
	}
}

void	sort_myself(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	nbinstack;

	nbinstack = get_last_index(*stack_a);
	while (nbinstack > 0 && i > 0)
	{
		if (verif_in_order(*stack_a) == 1)
		{
			if ((*stack_a)->binary[i] == '0')
				do_pb(stack_a, stack_b);
			else
			{
				if ((*stack_a)->next != NULL)
					do_ra(stack_a);
			}
		}
		nbinstack--;
	}
	if (i > 1)
		the_sort_stackb(stack_a, stack_b, i);
	if (i == 0)
		sort_the_end(stack_a, stack_b);
	return ;
}

int	push_big(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	last_index;

	last_index = get_last_index(*stack_a);
	i = ft_strlen((*stack_a)->binary) - 1;
	while (i >= 0)
	{
		sort_myself(stack_a, stack_b, i);
		i--;
	}
	return (SUCCES);
}
