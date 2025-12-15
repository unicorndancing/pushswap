/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:26:48 by mlapique          #+#    #+#             */
/*   Updated: 2024/04/03 16:20:24 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	presort(t_stack **stack_a, t_stack **stack_b, t_utils utils)
{
	while (utils.nbinstack-- > 0)
	{
		if (utils.nbsend == utils.max + utils.theplus)
			break ;
		if ((*stack_a)->suposed_place <= utils.max)
		{
			utils.nbsend++;
			do_pb(stack_a, stack_b);
		}
		else if ((*stack_a)->suposed_place <= utils.max + utils.theplus)
		{
			do_pb(stack_a, stack_b);
			utils.nbsend++;
			if ((*stack_b)->next != NULL && *stack_a \
			&& (*stack_a)->next != NULL \
			&& (*stack_a)->suposed_place > utils.max + utils.theplus)
				do_rr(stack_a, stack_b);
			else if ((*stack_b)->next != NULL)
				do_rb(stack_b);
		}
		else
			do_ra(stack_a);
	}
}

void	ipresort(t_stack **stack_a, t_stack **stack_b, int max, int theplus)
{
	t_utils	utils;

	utils.nbsend = 0;
	utils.nbinstack = get_last_index(*stack_a);
	utils.theplus = theplus;
	utils.max = max;
	presort(stack_a, stack_b, utils);
}
