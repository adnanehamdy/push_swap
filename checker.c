/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:11:59 by ahamdy            #+#    #+#             */
/*   Updated: 2021/12/22 11:12:20 by ahamdy           ###   ########.fr       */
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

void	print_error(void)
{
	ft_putstr("Error\n", 2);
	exit (1);
}

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*head0b;
	char	*get;

	if (ac == 1)
		return (0);
	head = ft_lstmap(av, ac);
	head0b = NULL;
	get = get_next_line(0);
	while (get)
	{
		check_inst(&head, &head0b, get);
		free(get);
		get = get_next_line(0);
	}
	if (!check_sort(head) && (!head0b))
		ft_putstr("OK\n", 1);
	else
		ft_putstr("KO\n", 1);
}
