/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:49:51 by mlapique          #+#    #+#             */
/*   Updated: 2024/04/03 15:48:58 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotaterr(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	ndmax;
	int	max;

	max = get_max_suposed_place(stack_b);
	ndmax = get_ndmax(stack_b);
	while ((*stack_b)->next != NULL)
	{
		if ((*stack_b)->suposed_place == max)
		{
			do_pa(stack_a, stack_b);
			if (ndmax == -1)
				do_sa(stack_a);
			break ;
		}
		else if ((*stack_b)->suposed_place == ndmax && i != 0)
		{
			do_pa(stack_a, stack_b);
			ndmax = -1;
		}
		else
			do_rrb(stack_b);
	}
	if ((*stack_b)->next == NULL)
		do_pa(stack_a, stack_b);
}

void	rotater(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	ndmax;

	ndmax = get_ndmax(stack_b);
	while ((*stack_b)->next != NULL)
	{
		if ((*stack_b)->suposed_place == get_max_suposed_place(stack_b))
		{
			do_pa(stack_a, stack_b);
			if (ndmax == -1)
				do_sa(stack_a);
			break ;
		}
		else if ((*stack_b)->suposed_place == ndmax && i != 0)
		{
			do_pa(stack_a, stack_b);
			ndmax = -1;
		}
		else
			do_rb(stack_b);
	}
	if ((*stack_b)->next == NULL)
		do_pa(stack_a, stack_b);
}

void	sort_little_by_little(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	which;

	which = way_to_rotate (stack_b);
	if (which == 0)
		rotater(stack_a, stack_b, i);
	else
		rotaterr(stack_a, stack_b, i);
	if ((*stack_b))
	{
		if ((*stack_b)->next == NULL)
		{
			if ((*stack_b)->suposed_place == 0)
				do_pa(stack_a, stack_b);
		}
	}
	if ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->suposed_place > (*stack_a)->next->suposed_place)
			do_sa(stack_a);
	}
	return ;
}

int	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	li;

	i = 0;
	li = get_last_index(*stack_a);
	while (i < li)
	{
		if (get_last_index(*stack_a) + get_last_index(*stack_b) > 250)
			ipresort(stack_a, stack_b, (li / 17) + (i * (li / 17)), (li / 17));
		else if (get_last_index(*stack_a) + get_last_index(*stack_b) > 10)
			ipresort(stack_a, stack_b, (li / 10) + (i * (li / 10)), (li / 10));
		else if (get_last_index(*stack_a) + get_last_index(*stack_b) < 10)
			ipresort(stack_a, stack_b, (li / 2) + (i * (li / 10)), (li / 2));
		i += 2;
	}
	if (stack_a)
		do_pb(stack_a, stack_b);
	while (is_sorted(*stack_a, *stack_b) != 1)
		sort_little_by_little(stack_a, stack_b, i);
	return (SUCCES);
}
