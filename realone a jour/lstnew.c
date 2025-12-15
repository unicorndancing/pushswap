/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:40:59 by mlapique          #+#    #+#             */
/*   Updated: 2024/03/03 18:08:06 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(int content)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	result->suposed_place = -1;
	result->integer = content;
	result->index = 0;
	result->suposed_place_temp = -1;
	result->next = NULL;
	result->binary = NULL;
	return (result);
}
