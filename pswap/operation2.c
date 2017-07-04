/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 08:30:28 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/15 18:18:53 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_closer_down(t_list_nb *begin_b)
{
	t_list_nb	*tmp;
	int			i;

	i = 0;
	tmp = begin_b;
	while (tmp)
	{
		if (tmp->nb == ft_get_max(begin_b))
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		ft_get_closer_up(t_list_nb *begin_b)
{
	t_list_nb	*tmp;
	int			i;
	int			len;
	int			go_end;
	int			result;

	i = 0;
	len = lstlen_a(begin_b);
	while (len)
	{
		tmp = begin_b;
		go_end = len;
		i = 0;
		while (i < go_end && tmp->next)
		{
			tmp = tmp->next;
			i++;
		}
		if (tmp->nb == ft_get_max(begin_b))
			break ;
		len--;
	}
	result = lstlen_a(begin_b) - tmp->pos;
	return (lstlen_a(begin_b) - tmp->pos + 1);
}

int		ft_get_closer_down_med(t_list_nb *begin, int median)
{
	t_list_nb	*tmp;
	int			i;

	i = 0;
	tmp = begin;
	while (tmp)
	{
		if (tmp->nb < median && tmp->nb != ft_get_max(begin))
			return (tmp->nb);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		ft_get_closer_up_med(t_list_nb *begin_b, int median)
{
	t_list_nb	*tmp;
	int			i;
	int			len;
	int			go_end;
	int			result;

	i = 0;
	len = lstlen_a(begin_b);
	while (len)
	{
		tmp = begin_b;
		go_end = len;
		i = 0;
		while (i < go_end && tmp->next)
		{
			tmp = tmp->next;
			i++;
		}
		if (tmp->nb < median)
			return (tmp->nb);
		len--;
	}
	result = lstlen_a(begin_b) - tmp->pos;
	return (lstlen_a(begin_b) - tmp->pos + 1);
}

int		get_quart_a(t_list_nb *begin, t_data *data, int len)
{
	int			*array;
	int			j;
	int			k;
	int			i;
	t_list_nb	*tmp;

	tmp = begin;
	k = 0;
	j = 0;
	array = split_array(begin);
	while (j++ <= len && k < len)
	{
		i = (lstlen_a(begin) * j) / len;
		data->quart[k] = array[i - 1];
		k++;
	}
	ft_memdel((void**)&array);
	return (0);
}
