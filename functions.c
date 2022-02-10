/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 09:01:52 by ahamdy            #+#    #+#             */
/*   Updated: 2021/12/21 17:14:22 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *head)
{
	int	i;

	if (!head || !(head)->next)
		return ;
	i = head->next->content;
	head->next->content = head->content;
	head->content = i;
	ft_putstr("sa\n", 1);
}

void	rev_rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp01;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	tmp01 = *head;
	while (tmp01->next->next)
		tmp01 = tmp01->next;
	*head = tmp01->next;
	tmp01->next = NULL;
	(*head)->next = tmp;
	ft_putstr("rra\n", 1);
}

void	rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp01;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	tmp01 = (*head)->next;
	(*head)->next = NULL;
	*head = tmp01;
	ft_putstr("ra\n", 1);
}

void	push_b(t_list **head, t_list **head0b)
{
	t_list	*tmp;

	if (!*head)
		return ;
	tmp = *head;
	*head = (*head)->next;
	ft_lstadd_front(head0b, tmp);
	ft_putstr("pb\n", 1);
}

void	push_a(t_list **head, t_list **head0b)
{
	t_list	*tmp;

	if (!*head0b)
		return ;
	tmp = *head;
	*head = *head0b;
	*head0b = (*head0b)->next;
	(*head)->next = tmp;
	ft_putstr("pa\n", 1);
}
