/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:15:35 by ahamdy            #+#    #+#             */
/*   Updated: 2021/12/21 13:26:09 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(char **av, int ac)
{
	t_list	*list;
	char	**up_av;
	int		i;
	int		j;

	list = 0;
	ac--;
	while (ac)
	{
		up_av = ft_split(av[ac], ' ');
		if (!up_av[0])
			print_error();
		i = 0;
		j = 0;
		while (up_av[j])
			j++;
		check_int(j, up_av, 1);
		i = j - 1;
		while (i >= 0)
			ft_lstadd_front(&list, ft_lstnew(ft_atoi(up_av[i--])));
		ft_free(up_av, j);
		ac--;
	}
	check_dup_list(list);
	return (list);
}

int	is_one(t_list *head, int shift)
{
	while (head)
	{
		if ((head->content >> shift) & 1)
			return (1);
		head = head->next;
	}
	return (0);
}

int	index_small_num(t_list *head)
{
	int	index;
	int	count;

	count = 1;
	index = ft_small_num(head);
	while (head)
	{
		if (head->content == index)
			return (count);
		count++;
		head = head->next;
	}
	return (-1);
}

void	print_error(void)
{
	ft_putstr("Error\n", 2);
	exit (1);
}

void	push_small(t_list **head, t_list **head0b)
{
	int	small_num;
	int	index;
	int	size;

	size = ft_lstsize(*head);
	while (size > 3)
	{
		small_num = ft_small_num(*head);
		index = index_small_num(*head);
		if (index >= 3)
		{
			while ((*head)->content != small_num)
				rev_rotate(head);
		}
		else
		{
			while ((*head)->content != small_num)
				rotate(head);
		}
		push_b(head, head0b);
		size--;
	}
}
