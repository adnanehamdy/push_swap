/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:34:36 by ahamdy            #+#    #+#             */
/*   Updated: 2021/12/21 11:45:52 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_big_num(t_list *head)
{
	int	big_num;

	big_num = head->content;
	while (head)
	{
		if (head->content > big_num)
			big_num = head->content;
		head = head->next;
	}
	return (big_num);
}

int	ft_small_num(t_list *head)
{
	int	small_num;

	small_num = head->content;
	while (head)
	{
		if (head->content < small_num)
			small_num = head->content;
		head = head->next;
	}
	return (small_num);
}

int	ft_mid_num(t_list *head)
{
	int		big_num;
	int		small_num;
	int		mid_num;

	big_num = ft_big_num(head);
	small_num = ft_small_num(head);
	mid_num = small_num;
	while (head)
	{
		if (head->content > mid_num && head->content < big_num)
			mid_num = head->content;
		head = head->next;
	}
	return (mid_num);
}

void	three_num(t_list **head)
{
	t_list	*tmp;

	tmp = (*head)->next;
	if (((*head)->content > tmp->content)
		&& ((*head)->content > ft_lstlast(*head)->content))
		rotate(head);
	tmp = (*head)->next;
	if (((*head)->content < tmp->content)
		&& (tmp->content > ft_lstlast(*head)->content))
		rev_rotate(head);
	tmp = (*head)->next;
	if ((*head)->content > tmp->content)
		swap(*head);
}

void	five_num(t_list **head, t_list **head0b)
{
	int	size;

	size = ft_lstsize(*head);
	push_small(head, head0b);
	three_num(head);
	if (size == 5)
		push_a(head, head0b);
	push_a(head, head0b);
	if ((*head)->content > (*head)->next->content)
		swap(*head);
}
