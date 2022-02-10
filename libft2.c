/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:14:50 by ahamdy            #+#    #+#             */
/*   Updated: 2021/12/21 11:29:02 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putstr(char *s, int fd)
{
	if (s)
	{
		while (*s)
			ft_putchar(*s++, fd);
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((unsigned char )s1[i] == (unsigned char)s2[i]
		&& (unsigned char )s1[i] && (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
