/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:32:38 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/17 14:16:36 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data		*initenv(void)
{
	t_data	*data;

	if (!(data = malloc(sizeof(t_data))))
		return (NULL);
	data->array = NULL;
	return (data);
}

void		ft_free_list(t_list_nb *begin)
{
	t_list_nb	*tmp;
	t_list_nb	*tmp2;
	int			i;

	i = 0;
	tmp = begin;
	tmp2 = begin;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
		i++;
	}
}

int			main(int argc, char **argv)
{
	int			i;
	t_list_nb	*begin_a;
	t_data		*data;

	i = 1;
	if (argc <= 2)
		return (0);
	begin_a = ft_lstinit(ft_atoi(argv[1]), 1);
	i++;
	while (i < argc)
	{
		put_in_list(ft_atoi(argv[i]), begin_a, i);
		i++;
	}
	data = initenv();
	if (handle_error(begin_a, argv) != 1)
		ft_pushswap(begin_a, data);
	else
		ft_putendl_fd("Error", 2);
	ft_memdel((void**)&data);
	return (0);
}
