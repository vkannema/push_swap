/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:38:09 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/17 14:17:36 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*split_array(t_list_nb *begin)
{
	t_list_nb	*tmp;
	int			*array;
	int			i;

	i = 0;
	tmp = begin;
	if (!(array = malloc(sizeof(int) * lstlen_a(begin))))
		return (NULL);
	while (tmp)
	{
		array[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	quicksort(array, 0, lstlen_a(begin) - 1);
	return (array);
}
