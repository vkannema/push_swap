/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 03:36:05 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/17 14:20:05 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void			swap_a(t_list_nb **begin_a, t_data *data)
{
	t_list_nb	*tmp;
	t_list_nb	*tmp2;

	if (!*(begin_a) || !(*begin_a)->next)
		return ;
	tmp = *begin_a;
	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	tmp->pos = 2;
	tmp2->pos = 1;
	*begin_a = tmp2;
	data->coups++;
}

void			swap_b(t_list_nb **begin_b, t_data *data)
{
	t_list_nb	*tmp;
	t_list_nb	*tmp2;

	if (!*begin_b || !(*begin_b)->next)
		return ;
	tmp = *begin_b;
	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	tmp->pos = 2;
	tmp2->pos = 1;
	*begin_b = tmp2;
	data->coups++;
}

static void		ft_reset_pos(t_list_nb *begin_a, t_list_nb *begin_b)
{
	int			i;
	t_list_nb	*tmp;
	t_list_nb	*tmpb;

	i = 1;
	tmp = begin_a;
	tmpb = begin_b;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
	i = 1;
	while (tmpb)
	{
		tmpb->pos = i;
		tmpb = tmpb->next;
		i++;
	}
}

void			push_a(t_list_nb **begin_a, t_list_nb **begin_b, t_data *data)
{
	t_list_nb	*tmp;
	t_list_nb	*tmp_b;

	if (!(*begin_b))
		return ;
	tmp_b = (*begin_b)->next;
	tmp = *begin_b;
	*begin_b = tmp_b;
	tmp->next = *begin_a;
	*begin_a = tmp;
	ft_reset_pos(*begin_a, *begin_b);
	data->coups++;
}

void			push_b(t_list_nb **begin_a, t_list_nb **begin_b, t_data *data)
{
	t_list_nb	*tmp;
	t_list_nb	*tmp_a;

	if (!*begin_a)
		return ;
	tmp_a = (*begin_a)->next;
	tmp = *begin_a;
	*begin_a = tmp_a;
	tmp->next = *begin_b;
	*begin_b = tmp;
	ft_reset_pos(*begin_a, *begin_b);
	data->coups++;
}
