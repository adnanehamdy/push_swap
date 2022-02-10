/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:51:34 by ahamdy            #+#    #+#             */
/*   Updated: 2021/12/21 15:44:07 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
