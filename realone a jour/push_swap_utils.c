/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:59:58 by mlapique          #+#    #+#             */
/*   Updated: 2024/04/03 16:33:47 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	way_to_rotate(t_stack **stack_b)
{
	int		max;
	int		ndmax;
	t_stack	*tmp;
	int		i;
	int		nb_instack;

	tmp = *stack_b;
	nb_instack = get_last_index(*stack_b) - 1;
	max = get_max_suposed_place(stack_b);
	ndmax = get_ndmax(stack_b);
	i = 0;
	while (i <= nb_instack)
	{
		if (tmp->suposed_place == max)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i < (nb_instack / 2))
		return (0);
	else
		return (1);
}

int	get_max_suposed_place(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = -1;
	while (tmp)
	{
		if (tmp->suposed_place > max)
			max = tmp->suposed_place;
		tmp = tmp->next;
	}
	return (max);
}

int	get_ndmax(t_stack **stack)
{
	int		max;
	int		ndmax;
	t_stack	*tmp;

	tmp = *stack;
	max = get_max_suposed_place(stack);
	ndmax = -1;
	while (tmp)
	{
		if (tmp->suposed_place > ndmax && tmp->suposed_place != max)
			ndmax = tmp->suposed_place;
		tmp = tmp->next;
	}
	return (ndmax);
}

int	verif_in_order(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = stack_a;
	temp2 = stack_a->next;
	while (temp2)
	{
		if (temp->suposed_place >= temp2->suposed_place)
			return (1);
		temp = temp->next;
		temp2 = temp2->next;
	}
	return (0);
}

int	way_to_rotate_presort(t_stack **stack_b, int max)
{
	t_stack	*tmp;
	int		i;
	int		nb_instack;
	int		first;
	int		last;

	last = 0;
	first = 0;
	tmp = *stack_b;
	nb_instack = get_last_index(*stack_b) - 1;
	i = 0;
	while (i <= nb_instack)
	{
		if (tmp->suposed_place <= max && first == 0)
			first = i;
		else if (tmp->suposed_place <= max && first > 0)
			last = i;
		tmp = tmp->next;
		i++;
	}
	if (first < nb_instack - last + (nb_instack / 10))
		return (1);
	else
		return (0);
}
