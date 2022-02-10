/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:35:37 by ahamdy            #+#    #+#             */
/*   Updated: 2021/12/21 17:17:37 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_checker(t_list *head)
{
	int	i;

	if (!head || !(head)->next)
		return ;
	i = head->next->content;
	head->next->content = head->content;
	head->content = i;
}

void	rev_rotate_checker(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp01;

	tmp = *head;
	tmp01 = *head;
	if (!*head || !(*head)->next)
		return ;
	while (tmp01->next->next)
		tmp01 = tmp01->next;
	*head = tmp01->next;
	tmp01->next = NULL;
	(*head)->next = tmp;
}

void	rotate_checker(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp01;

	tmp = *head;
	if (!*head || !(*head)->next)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	tmp01 = (*head)->next;
	(*head)->next = NULL;
	*head = tmp01;
}

void	push_b_checker(t_list **head, t_list **head0b)
{
	t_list	*tmp;

	if (!*head)
		return ;
	tmp = *head;
	*head = (*head)->next;
	ft_lstadd_front(head0b, tmp);
}

void	push_a_checker(t_list **head, t_list **head0b)
{
	t_list	*tmp;

	if (!*head0b)
		return ;
	tmp = *head;
	*head = *head0b;
	*head0b = (*head0b)->next;
	(*head)->next = tmp;
}
