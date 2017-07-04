/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 03:37:18 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/15 18:18:57 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reset_pos(t_list_nb *begin)
{
	int			i;
	t_list_nb	*tmp;

	i = 1;
	tmp = begin;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void		rotate_b(t_list_nb **begin_b)
{
	t_list_nb	*tmp;
	t_list_nb	*tmp2;

	tmp = *begin_b;
	tmp2 = tmp->next;
	while (tmp->next)
		tmp = tmp->next;
	(*begin_b)->next = NULL;
	tmp->next = *begin_b;
	*begin_b = tmp2;
	ft_reset_pos(*begin_b);
	ft_putendl("rb");
}

void		reverse_b(t_list_nb **begin_b)
{
	t_list_nb	*tmp;
	t_list_nb	*tmp2;

	tmp = *begin_b;
	tmp2 = *begin_b;
	while (tmp2->next)
	{
		if (tmp2->next->next == NULL)
			tmp = tmp2;
		tmp2 = tmp2->next;
	}
	tmp->next = NULL;
	tmp2->next = *begin_b;
	*begin_b = tmp2;
	ft_reset_pos(*begin_b);
	ft_putendl("rrb");
}

void		rotate_a(t_list_nb **begin_a)
{
	t_list_nb	*tmp;
	t_list_nb	*tmp2;

	tmp = *begin_a;
	tmp2 = tmp->next;
	while (tmp->next)
		tmp = tmp->next;
	(*begin_a)->next = NULL;
	tmp->next = *begin_a;
	*begin_a = tmp2;
	ft_reset_pos(*begin_a);
	ft_putendl("ra");
}

void		reverse_a(t_list_nb **begin_a)
{
	t_list_nb	*tmp;
	t_list_nb	*tmp2;

	tmp = *begin_a;
	tmp2 = *begin_a;
	while (tmp2->next)
	{
		if (tmp2->next->next == NULL)
			tmp = tmp2;
		tmp2 = tmp2->next;
	}
	tmp->next = NULL;
	tmp2->next = *begin_a;
	*begin_a = tmp2;
	ft_reset_pos(*begin_a);
	ft_putendl("rra");
}
