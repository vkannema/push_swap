/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:02:18 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/15 18:59:59 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list_nb	*put_in_first(t_list_nb *begin_a, t_data *data)
{
	t_list_nb	*tmp;
	int			max;

	tmp = begin_a;
	max = data->array[lstlen_a(begin_a) - 1];
	while (tmp->nb != max && tmp)
		tmp = tmp->next;
	if (ft_define_shorter(tmp, lstlen_a(begin_a), 1) == 0)
	{
		while (tmp->pos != 1)
			reverse_a(&begin_a);
	}
	else
		while (tmp->pos != 1)
			rotate_a(&begin_a);
	return (begin_a);
}

t_list_nb			*ft_for_3(t_list_nb *begin_a, t_data *data)
{
	t_list_nb	*tmp;

	while (!ft_is_croi(begin_a))
	{
		tmp = ft_go_last(begin_a);
		if (ft_find_next(begin_a, begin_a->nb, data->array) == data->array[0]
		&& begin_a->nb == ft_get_max(begin_a))
			rotate_a(&begin_a);
		else if (tmp->nb == data->array[0] &&
		ft_find_previous(begin_a, begin_a->nb, data->array) == data->array[0])
			reverse_a(&begin_a);
		else
			swap_a(&begin_a);
	}
	return (begin_a);
}

t_list_nb			*ft_for_more(t_list_nb *begin_a, t_list_nb *begin_b,
	t_data *data, int len)
{
	if (!ft_is_croi(begin_a))
	{
		while (lstlen_a(begin_a) > 3)
		{
			begin_a = put_in_first(begin_a, data);
			push_b(&begin_a, &begin_b);
		}
		begin_a = ft_for_3(begin_a, data);
		while (lstlen_a(begin_a) < len)
		{
			push_a(&begin_a, &begin_b);
			rotate_a(&begin_a);
		}
	}
	return (begin_a);
}
