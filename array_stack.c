/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:18:49 by ahamdy            #+#    #+#             */
/*   Updated: 2021/12/22 10:58:53 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_sort(int *array, int size)
{
	int	j;
	int	i;
	int	tmp;

	j = 0;
	while (j < size)
	{
		i = 1;
		while (i < size)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
			}
			i++;
		}
		j++;
	}
}

int	*array_index(t_list *head)
{
	int		size;
	int		*array;
	int		i;

	i = 0;
	size = ft_lstsize(head);
	array = (int *)malloc(sizeof(int) * (size));
	while (head)
	{
		array[i++] = head->content;
		head = head->next;
	}
	array_sort(array, size);
	return (array);
}

void	index_stack(t_list *head)
{
	int	*array;
	int	count;
	int	i;

	count = 0;
	i = 0;
	array = array_index(head);
	while (head)
	{
		i = 0;
		while (head->content != array[i])
			i++;
		if (head->content == array[i])
			head->content = i;
		head = head->next;
	}
	free(array);
}

void	shift_stack(t_list **head, t_list **head0b)
{
	int		shift;
	int		size;
	int		j;

	shift = 0;
	index_stack(*head);
	size = ft_lstsize(*head);
	while (check_sort(*head) || (*head0b))
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*head)->content >> shift) & 1) == 0)
				push_b(head, head0b);
			else
				rotate(head);
			if (!check_sort(*head) && !*head0b)
				exit (0);
		}
		while (*head0b)
			push_a(head, head0b);
		shift++;
	}
}

int	check_sort(t_list *head)
{
	while (head && head->next)
	{
		if (head->content < head->next->content)
			head = head->next;
		else
			return (1);
	}
	return (0);
}
