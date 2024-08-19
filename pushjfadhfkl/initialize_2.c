/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:19:30 by mlapique          #+#    #+#             */
/*   Updated: 2024/03/18 14:29:31 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*binary(int nb, int len_nb)
{
	char	*binary;
	char	*result;
	int		i;

	i = 0;
	binary = "01";
	result = ft_calloc (len_nb + 1, 1);
	if (!result)
		return (NULL);
	while (i < len_nb)
	{
		result[i] = '0';
		i++;
	}
	while (nb >= 1)
	{
		result[len_nb - 1] = binary[nb % 2];
		nb = nb / 2;
		len_nb--;
	}
	return (result);
}

int	transform_to_binary(t_stack *stack_a)
{
	int		max;
	t_stack	*temp;
	int		len_nb;

	len_nb = 1;
	max = get_last_index(stack_a);
	temp = stack_a;
	while (max >= 1)
	{
		max = max / 2;
		len_nb++;
	}
	while (temp)
	{
		temp->binary = binary(temp->suposed_place, len_nb);
		if (temp->binary == NULL)
			return (-1);
		temp = temp->next;
	}
	return (0);
}
