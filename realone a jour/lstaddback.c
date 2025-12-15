/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstaddback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:46:59 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/19 11:59:34 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_stack_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_lstlas(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd(t_stack *lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (lst)
	{
		last = ft_lstlas(lst);
		last->next = new;
	}
	else
		lst = new;
}
