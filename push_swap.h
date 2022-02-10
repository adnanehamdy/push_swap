/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:18:25 by ahamdy            #+#    #+#             */
/*   Updated: 2021/12/22 11:09:04 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}t_list;
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
long	ft_atoi(const char *str);
void	ft_lstdelone(t_list *lst);
int		ft_isdigit(int c);
void	swap(t_list *head);
void	rotate(t_list **head);
void	rev_rotate(t_list **head);
t_list	*ft_lstmap(char **av, int ac);
void	ft_lstclear(t_list **lst);
void	ft_putchar(char c, int fd);
void	ft_putstr(char *s, int fd);
void	check_dup(int ac, char **av);
int		ft_strcmp(const char *s1, const char *s2);
void	push_b(t_list **head, t_list **head0b);
void	push_a(t_list **head, t_list **head0b);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_free(char **split, size_t j);
void	check_int(int ac, char **av, int dup);
t_list	*ft_lstlast(t_list *lst);
void	three_num(t_list **head);
int		ft_mid_num(t_list *head);
void	check_space(int ac, char **av);
void	print_error(void);
void	five_num(t_list **head, t_list **head0b);
int		ft_lstsize(t_list *lst);
int		*array_index(t_list *head);
void	check_dup_list(t_list *head);
void	index_stack(t_list *head);
void	shift_stack(t_list **head, t_list **head0b);
int		check_sort(t_list *head);
int		is_one(t_list *head, int shift);
int		index_small_num(t_list *head);
int		ft_small_num(t_list *head);
void	push_small(t_list **head, t_list **head0b);

/*-------------------------get_next_line_________________*/
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);

/*-----------------------checker-----------------------*/
void	swap_checker(t_list *head);
void	rev_rotate_checker(t_list **head);
void	rotate_checker(t_list **head);
void	push_b_checker(t_list **head, t_list **head0b);
void	push_a_checker(t_list **head, t_list **head0b);
void	check_inst(t_list **head, t_list **head0b, char *get);
void	ft_check_inst2(t_list **head, t_list **head0b, char *get);
#endif