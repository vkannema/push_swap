/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:22:31 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/17 14:17:11 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_find_next(t_list_nb *begin, int nb, int *array)
{
	int	i;
	int	next;

	i = 0;
	if (nb == ft_get_max(begin))
		return (ft_get_min(begin));
	while (i < lstlen_a(begin) - 1 && array[i] != nb)
		i++;
	next = array[i + 1];
	return (next);
}

int			ft_find_previous(t_list_nb *begin, int nb, int *array)
{
	int	i;
	int	previous;

	i = 0;
	if (nb == ft_get_min(begin))
		return (ft_get_max(begin));
	while (i < lstlen_a(begin) - 1 && array[i] != nb)
		i++;
	previous = array[i - 1];
	return (previous);
}

int			ft_get_median(t_list_nb *begin)
{
	int			*array;
	int			i;
	t_list_nb	*tmp;
	int			ind;
	int			med;

	tmp = begin;
	i = 0;
	if (!(array = malloc(sizeof(int) * lstlen_a(begin))))
		return (0);
	while (tmp)
	{
		array[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	quicksort(array, 0, lstlen_a(begin) - 1);
	ind = lstlen_a(begin) / 2;
	med = array[ind];
	return (med);
}

int			ft_define_shorter(t_list_nb *elem, int len, int pos)
{
	int	movesrotate;
	int	movesreverse;
	int pos_start;
	int	ind;

	movesrotate = 0;
	movesreverse = 0;
	ind = elem->pos;
	pos_start = ind;
	while (pos_start >= pos)
	{
		movesreverse++;
		pos_start--;
	}
	pos_start = ind;
	while (pos_start <= len)
	{
		movesrotate++;
		pos_start++;
	}
	movesrotate++;
	if (movesreverse > movesrotate)
		return (0);
	return (1);
}

t_list_nb	*ft_go_last(t_list_nb *begin_a)
{
	t_list_nb *ret;

	ret = begin_a;
	while (ret->next)
		ret = ret->next;
	return (ret);
}
