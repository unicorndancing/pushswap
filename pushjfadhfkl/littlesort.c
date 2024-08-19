/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   littlesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:21:38 by mlapique          #+#    #+#             */
/*   Updated: 2024/03/23 16:07:49 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tempsuposed_place(t_stack **stack)
{
	int		i;
	t_stack	*temp;
	t_stack	*higher;

	higher = *stack;
	temp = *stack;
	i = get_last_index(*stack);
	while (i > 0)
	{
		while (temp)
		{
			if ((temp->integer > higher->integer
					&& temp->suposed_place_temp == -1)
				|| higher->suposed_place_temp != -1)
				higher = temp;
			temp = temp->next;
		}
		higher->suposed_place_temp = i - 1;
		i--;
		temp = *stack;
		higher = *stack;
	}
}

void	do_the_little_sort(t_stack **stack_a, t_stack **stack_b)
{
	tempsuposed_place(stack_a);
	if ((*stack_a)->suposed_place_temp == 1)
	{
		if ((*stack_a)->next->suposed_place_temp == 0)
			do_sa(stack_a);
		else
			do_rra(stack_a);
	}
	else if ((*stack_a)->suposed_place_temp == 0)
	{
		if ((*stack_a)->next->suposed_place_temp == 2)
		{
			do_pb(stack_a, stack_b);
			do_ra(stack_a);
			do_pa(stack_a, stack_b);
		}
	}
	else if ((*stack_a)->suposed_place_temp == 2)
	{
		do_ra(stack_a);
		if ((*stack_a)->suposed_place_temp == 1)
			do_sa(stack_a);
	}
}

void	do_the_less_little_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (get_last_index((*stack_b)) != 1)
	{
		if ((*stack_a)->suposed_place == 0)
			do_pb(stack_a, stack_b);
		else if ((*stack_b) == NULL)
			do_ra(stack_a);
	}
	do_the_little_sort(stack_a, stack_b);
	do_pa(stack_a, stack_b);
}

void	do_the_less_less_little_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (get_last_index(*stack_b) != 2)
	{
		if ((*stack_a)->suposed_place == 0 || (*stack_a)->suposed_place == 1)
		{
			do_pb(stack_a, stack_b);
		}
		else
			do_ra(stack_a);
	}
	do_the_little_sort(stack_a, stack_b);
	if ((*stack_b)->suposed_place < (*stack_b)->next->suposed_place)
		do_rb(stack_b);
	do_pa(stack_a, stack_b);
	do_pa(stack_a, stack_b);
}

void	what_sort_is_best_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	li;

	li = get_last_index(*stack_a);
	if (li == 2)
		do_sa(stack_a);
	else if (li == 3)
		do_the_little_sort(stack_a, stack_b);
	else if (li == 4)
		do_the_less_little_sort(stack_a, stack_b);
	else if (li == 5)
		do_the_less_less_little_sort(stack_a, stack_b);
	else if (li < 725)
		push_swap(stack_a, stack_b);
	else
		push_big(stack_a, stack_b);
}
