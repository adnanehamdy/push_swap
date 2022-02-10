/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:42:18 by ahamdy            #+#    #+#             */
/*   Updated: 2021/12/22 11:08:55 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(int ac, char **av)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (count < ac)
	{
		i = count + 1;
		while (i < ac)
		{
			if (ft_atoi(av[count]) == ft_atoi(av[i]))
				print_error();
			i++;
		}
		count++;
	}
}

void	check_dup_list(t_list *head)
{
	t_list	*head01;
	t_list	*save;

	save = head;
	while (head)
	{
		head01 = head->next;
		while (head01)
		{
			if (head->content == head01->content)
				print_error();
			head01 = head01->next;
		}
		head = head->next;
	}
}

void	check_int(int ac, char **av, int dup)
{
	int		count;
	int		i;
	long	c;

	i = 0;
	count = 0;
	while (count < ac)
	{
		c = ft_atoi(av[count]);
		if ((c < -2147483648) || (c > 2147483647))
			print_error();
		count++;
	}
	if (dup == 1)
		check_dup(ac, av);
}

void	num_sort(t_list **head, t_list **head0b)
{
	int	size;

	size = ft_lstsize(*head);
	if (size <= 3)
		three_num(head);
	else if (size <= 5)
		five_num(head, head0b);
	else
		shift_stack(head, head0b);
}

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*head0b;

	if (ac == 1)
		return (0);
	head0b = NULL;
	head = ft_lstmap(av, ac);
	if (!check_sort(head) || (head0b))
		exit (0);
	num_sort(&head, &head0b);
	return (0);
}
