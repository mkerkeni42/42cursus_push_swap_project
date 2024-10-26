/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:09:58 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/26 12:12:22 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_lst *lst)
{
	t_pile	*tmp;
	t_move	*next;

	if (lst->b != NULL)
	{
		tmp = lst->b;
		lst->b = lst->b->next;
		tmp->next = lst->a;
		lst->a = tmp;
		next = ft_lstnew_move("pa\n");
		ft_lstadd_back_move(&(lst->move_list), next);
	}
}

void	push_b(t_lst *lst)
{
	t_pile	*tmp;
	t_move	*next;

	if (lst->a != NULL)
	{
		tmp = lst->a;
		lst->a = lst->a->next;
		tmp->next = lst->b;
		lst->b = tmp;
		next = ft_lstnew_move("pb\n");
		ft_lstadd_back_move(&(lst->move_list), next);
	}
}
