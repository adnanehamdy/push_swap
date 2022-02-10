/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:01:53 by ahamdy            #+#    #+#             */
/*   Updated: 2021/12/21 13:47:06 by ahamdy           ###   ########.fr       */
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
		if ((c < INT_MIN) || (c > INT_MAX))
			print_error();
		count++;
	}
	if (dup == 1)
		check_dup(ac, av);
}

void	print_error(void)
{
	ft_putstr("Error\n", 2);
	exit (1);
}
