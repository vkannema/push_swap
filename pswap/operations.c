/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:20:15 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/15 18:18:54 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_is_dec(t_list_nb *begin)
{
	t_list_nb *tmp;

	tmp = begin;
	while (tmp->next)
	{
		if (tmp->nb < tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			ft_is_croi(t_list_nb *begin)
{
	t_list_nb *tmp;

	tmp = begin;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			ft_get_max(t_list_nb *begin)
{
	t_list_nb	*tmp;
	int			max;

	tmp = begin;
	max = tmp->nb;
	while (tmp)
	{
		if (tmp->nb > max)
			max = tmp->nb;
		tmp = tmp->next;
	}
	return (max);
}

int			ft_get_min(t_list_nb *begin)
{
	t_list_nb	*tmp;
	int			min;

	tmp = begin;
	min = tmp->nb;
	while (tmp)
	{
		if (tmp->nb < min)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}

int			ft_get_under(t_list_nb *begin_a, int av)
{
	t_list_nb	*tmp;
	int			nb;

	nb = 0;
	tmp = begin_a;
	while (tmp)
	{
		if (tmp->nb < av)
			nb++;
		tmp = tmp->next;
	}
	return (nb);
}
