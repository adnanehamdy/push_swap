/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:18:12 by ahamdy            #+#    #+#             */
/*   Updated: 2022/02/10 12:01:21 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int cont)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (0);
	head->cont = content;
	head->next = NULL;
	return (head);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
	{
		ft_lstclear(lst);
		ft_putstr("Error\n", 2);
		exit (1);
	}
	new->next = *lst;
	*lst = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;
	t_list	*ptr2;

	ptr = *lst;
	if (!*lst)
		return ;
	while (ptr)
	{
		ptr2 = ptr->next;
		ft_lstdelone(ptr);
		ptr = ptr2;
	}
	*lst = 0;
}

static long	store(const char *str, int sign)
{
	size_t	res;

	res = 0;
	while (ft_isdigit(*str) && *str)
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	if (*str)
	{
		ft_putstr("Error\n", 2);
		exit (1);
	}
	return (sign * (long)res);
}

long	ft_atoi(const char *str)
{
	size_t	sign;
	size_t	res;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!*str)
	{
		ft_putstr("Error\n", 2);
		exit (1);
	}
	return (store(str, sign));
}
