/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 11:33:14 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/21 15:45:16 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_array(int *array, int a, int b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

void		quicksort(int *array, int start, int end)
{
	int			left;
	int			right;
	int			pivot;

	right = end + 1;
	pivot = array[start];
	left = start - 1;
	if (start >= end)
		return ;
	while (1)
	{
		right--;
		while (array[right] > pivot && right > 0)
			right--;
		left++;
		while (array[left] < pivot && left < end)
			left++;
		if (left < right)
			swap_array(array, left, right);
		else
			break ;
	}
	quicksort(array, start, right);
	quicksort(array, right + 1, end);
}

int			little_list(t_list_nb *begin_a, t_list_nb *begin_b, t_data *data)
{
	t_list_nb	*tmp;
	int			i;

	i = 0;
	tmp = begin_a;
	if (!(data->array = malloc(sizeof(int) * lstlen_a(begin_a))))
		return (0);
	while (tmp)
	{
		data->array[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	quicksort(data->array, 0, lstlen_a(begin_a) - 1);
	tmp = begin_a;
	if (lstlen_a(begin_a) == 2 && !ft_is_croi(begin_a))
		swap_a(&begin_a);
	else if (lstlen_a(begin_a) <= 3)
		begin_a = ft_for_3(begin_a, data);
	else
		begin_a = ft_for_more(begin_a, begin_b, data, lstlen_a(begin_a));
	ft_memdel((void **)&data->array);
	ft_free_list(begin_a);
	return (0);
}

int			ft_pushswap(t_list_nb *begin_a, t_data *data)
{
	t_list_nb	*begin_b;

	begin_b = NULL;
	if (lstlen_a(begin_a) <= 7)
		return (little_list(begin_a, begin_b, data));
	if (!ft_is_croi(begin_a))
		big_lists(begin_a, begin_b, data);
	return (0);
}
