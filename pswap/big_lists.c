/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:04:22 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/17 14:15:56 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_all_supp(t_list_nb *begin_b, int median)
{
	t_list_nb *tmp;

	tmp = begin_b;
	while (tmp)
	{
		if (tmp->nb < median)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	lensplit(t_list_nb *begin, t_data *data)
{
	int len;

	if (lstlen_a(begin) > 7 && lstlen_a(begin) < 200)
		len = 5;
	if (lstlen_a(begin) > 200)
		len = 12;
	if (!(data->quart = (int*)malloc(sizeof(int) * len)))
		return (0);
	get_quart_a(begin, data, len);
	return (len);
}

t_list_nb	*closer_split(t_list_nb *begin_a, t_data *data, int i)
{
	if (ft_get_closer_down_med(begin_a, data->quart[i]) <=
	ft_get_closer_up_med(begin_a, data->quart[i]))
	{
		while (begin_a->nb > data->quart[i] && begin_a->next)
			rotate_a(&begin_a);
	}
	if (ft_get_closer_down_med(begin_a, data->quart[i]) >=
	ft_get_closer_up_med(begin_a, data->quart[i]))
	{
		while (begin_a->nb > data->quart[i] && begin_a->next)
			reverse_a(&begin_a);
	}
	return (begin_a);
}

void		splitlist(t_list_nb **begin_a, t_list_nb **begin_b, t_data *data,
	int len)
{
	int	i;
	int	max;

	i = 0;
	while (i < len)
	{
		while (!(is_all_supp(*begin_a, data->quart[i])))
		{
			*begin_a = closer_split(*begin_a, data, i);
			max = ft_get_max(*begin_a);
			if ((*begin_a)->next && (*begin_a)->nb != max)
				push_b(begin_a, begin_b);
			if ((*begin_a)->nb == max && (*begin_a)->next)
				rotate_a(begin_a);
			get_quart_a(*begin_a, data, len);
		}
		i++;
	}
}

int			big_lists(t_list_nb *begin_a, t_list_nb *begin_b, t_data *data)
{
	t_list_nb	*tmp;
	int			len;

	tmp = begin_a;
	len = lensplit(begin_a, data);
	splitlist(&begin_a, &begin_b, data, len);
	while (begin_b)
	{
		if (ft_get_closer_down(begin_b) <= ft_get_closer_up(begin_b))
		{
			while (begin_b->nb != ft_get_max(begin_b))
				rotate_b(&begin_b);
		}
		else if (ft_get_closer_down(begin_b) >= ft_get_closer_up(begin_b))
		{
			while (begin_b->nb != ft_get_max(begin_b))
				reverse_b(&begin_b);
		}
		push_a(&begin_a, &begin_b);
	}
	free(data->quart);
	ft_free_list(begin_a);
	return (0);
}
