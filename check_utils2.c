/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:30:57 by ahamdy            #+#    #+#             */
/*   Updated: 2021/12/21 15:45:13 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_inst(t_list **head, t_list **head0b, char *get)
{
	if (!ft_strcmp(get, "ra\n"))
		rotate_checker(head);
	else if (!ft_strcmp(get, "rra\n"))
		rev_rotate_checker(head);
	else if (!ft_strcmp(get, "sa\n"))
		swap_checker(*head);
	else if (!ft_strcmp(get, "sb\n"))
		swap_checker(*head0b);
	else if (!ft_strcmp(get, "ss\n"))
	{
		swap_checker(*head);
		swap_checker(*head0b);
	}
	else
		ft_check_inst2(head, head0b, get);
}

void	ft_check_inst2(t_list **head, t_list **head0b, char *get)
{
	if (!ft_strcmp(get, "pa\n"))
		push_a_checker(head, head0b);
	else if (!ft_strcmp(get, "pb\n"))
		push_b_checker(head, head0b);
	else if (!ft_strcmp(get, "rb\n"))
		rotate_checker(head0b);
	else if (!ft_strcmp(get, "rrb\n"))
		rev_rotate_checker(head0b);
	else if (!ft_strcmp(get, "rr\n"))
	{
		rotate_checker(head);
		rotate_checker(head0b);
	}
	else if (!ft_strcmp(get, "rrr\n"))
	{
		rev_rotate_checker(head);
		rev_rotate_checker(head0b);
	}
	else
	{
		ft_putstr("Error\n", 2);
		exit (1);
	}
}
