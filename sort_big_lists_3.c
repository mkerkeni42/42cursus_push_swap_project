/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_lists_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:09:20 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/26 12:28:43 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_up_value_b(t_lst *lst, int val_b)
{
	t_pile	*middle_b;

	middle_b = get_middle(lst->b);
	if (lst->b->index == val_b)
		return ;
	if (check_position(lst->b, val_b, middle_b) == 1)
	{
		while (lst->b->index != val_b)
			rotate_b(lst);
	}
	else
	{
		while (lst->b->index != val_b)
			reverse_rotate_b(lst);
	}
}

static void	put_up_value_a(t_lst *lst, int val_a, int bool)
{
	if (bool == 0)
	{
		while (lst->a->index != val_a)
			rotate_a(lst);
	}
	else
	{
		while (lst->a->index != val_a)
			reverse_rotate_a(lst);
	}
}

int	get_closest_nb(t_pile *lst, int value, int max)
{
	t_pile	*tmp;
	int		nb;

	tmp = lst;
	nb = max;
	while (tmp != NULL)
	{	
		if (tmp->index > value && tmp->index - value < nb - value)
			nb = tmp->index;
		tmp = tmp->next;
	}
	return (nb);
}

void	match_best_values(t_lst *lst, int val_a, int val_b)
{
	t_pile	*middle_a;
	t_pile	*middle_b;

	middle_a = get_middle(lst->a);
	middle_b = get_middle(lst->b);
	if (check_position(lst->a, val_a, middle_a) == 1)
	{
		if (check_position(lst->b, val_b, middle_b) == 1
			&& lst->b->index != val_b)
		{
			while (lst->a->index != val_a && lst->b->index != val_b)
				rotate_a_and_b(lst);
		}
		put_up_value_a(lst, val_a, 0);
	}
	else
	{
		if (check_position(lst->b, val_b, middle_b) == 0)
		{
			while (lst->a->index != val_a && lst->b->index != val_b)
				reverse_rotate_a_and_b(lst);
		}
		put_up_value_a(lst, val_a, 1);
	}
	put_up_value_b(lst, val_b);
	push_a(lst);
}