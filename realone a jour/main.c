/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:42:54 by mlapique          #+#    #+#             */
/*   Updated: 2024/03/20 14:05:54 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_dothething(char *argv[])
{
	int		i;
	char	**split;

	i = 1;
	split = argv;
	while (argv[i])
	{
		split[i - 1] = argv[i];
		i++;
	}
	split[i - 1] = NULL;
	return (split);
}

int	is_sorted(t_stack *stacka, t_stack *stackb)
{
	t_stack	*temp;

	temp = stacka;
	if (stackb != NULL)
		return (0);
	while (temp && temp->next)
	{
		if (temp->suposed_place > temp->next->suposed_place)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	verif_suposed_place_empty(char *argv[])
{
	int	i;

	i = 1;
	if (argv[1][0] == '\0')
		return (error(NOT_A_NUMBER));
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (error(NOT_A_NUMBER));
		i++;
	}
	return (0);
}

int	test(char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split;

	split = ft_split(argv[1], ' ');
	if (split == NULL)
		return (error(MALLOC));
	if (verif_value_ini(split) == -1)
		return (free_argv(split), -1);
	stack_a = malloc(sizeof (t_stack));
	if (!stack_a)
		return (error(MALLOC));
	stack_b = NULL;
	if (ini_stack(split, stack_a) == -1)
		return (error(MALLOC));
	if (is_sorted(stack_a, stack_b) == 0)
		what_sort_is_best_sort(&stack_a, &stack_b);
	return (free_argv(split), free_stack(stack_a), 0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split;

	if (argc < 2)
		return (0);
	if (verif_suposed_place_empty(argv) < 0)
		return (0);
	if (argc == 2)
		return (test(argv));
	split = ft_dothething(argv);
	if (verif_value_ini(split) == -1)
		return (-1);
	stack_a = malloc(sizeof (t_stack));
	if (!stack_a)
		return (error(MALLOC));
	stack_b = NULL;
	if (ini_stack(split, stack_a) == -1)
		return (error(MALLOC));
	if (is_sorted(stack_a, stack_b) == 0)
		what_sort_is_best_sort(&stack_a, &stack_b);
	return (free_stack(stack_a), 0);
}
