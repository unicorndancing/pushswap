/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:45:46 by mlapique          #+#    #+#             */
/*   Updated: 2024/03/18 15:47:22 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(int Error_code)
{
	if (Error_code == NOT_A_NUMBER)
		write (2, "Error\n", 6);
	else if (Error_code == NOT_AN_INTEGER)
		write (2, "Error\n", 6);
	else if (Error_code == TOO_MANY_ZERO)
		write (2, "Error\n", 6);
	else if (Error_code == DOUBLE)
		write (2, "Error\n", 6);
	else if (Error_code == MALLOC)
		write (2, "Error\n", 6);
	else if (Error_code == ONE_NUMBER)
		return (-1);
	return (-1);
}
