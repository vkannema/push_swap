/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:54:34 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/15 17:01:06 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list_nb	*ft_lstinit(int nb, int pos)
{
	t_list_nb	*new_elem;

	if (!(new_elem = malloc(sizeof(t_list_nb))))
		return (NULL);
	new_elem->nb = nb;
	new_elem->pos = pos;
	new_elem->next = NULL;
	return (new_elem);
}

void		put_in_list(int nb, t_list_nb *begin, int pos)
{
	t_list_nb	*tmp;

	tmp = begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_lstinit(nb, pos);
}

int			lstlen_a(t_list_nb *begin)
{
	int			i;
	t_list_nb	*tmp;

	i = 0;
	tmp = begin;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
