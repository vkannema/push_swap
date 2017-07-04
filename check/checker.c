/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:22:09 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/16 10:24:34 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int			is_sort(t_list_nb *begin_a, t_list_nb *begin_b, t_data *data)
{
	t_list_nb	*tmp;
	t_list_nb	*tmp2;

	tmp = begin_a;
	if (begin_b)
	{
		ft_putendl_fd("KO", 2);
		return (0);
	}
	while (tmp->next)
	{
		if (tmp->next->nb < tmp->nb)
		{
			ft_free_list(begin_a);
			ft_putendl_fd("KO", 2);
			return (1);
		}
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if (data->color == 1)
		ft_print_list_complete(begin_a, data);
	ft_printf("OK\n");
	return (0);
}

static int	compare_op(t_list_nb **begin_a, t_list_nb **begin_b, t_data *data,
	char *move)
{
	if (ft_strlen(move) > 3)
		return (1);
	if (ft_strnstr(move, "sa", 2) && ft_strlen(move) < 3)
	{
		swap_a(begin_a, data);
		return (0);
	}
	else if (ft_strnstr(move, "sb", 2) && ft_strlen(move) < 3)
	{
		swap_b(begin_b, data);
		return (0);
	}
	else if (ft_strnstr(move, "ss", 2) && ft_strlen(move) < 3)
	{
		swap_a(begin_a, data);
		swap_b(begin_b, data);
		return (0);
	}
	else if (compare_op1(begin_a, begin_b, data, move) == 0)
		return (0);
	else
		return (1);
}

int			checker(t_list_nb *begin_a, t_list_nb *begin_b, t_data *data)
{
	char	*line;

	if (data->historic == 1)
		ft_print_list(begin_a, begin_b, "");
	line = NULL;
	while (get_next_line(0, &line))
	{
		if (compare_op(&begin_a, &begin_b, data, line) == 1)
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		if (data->mov)
		{
			usleep(40000);
			ft_printf("\033[2J");
		}
		if (data->historic == 1)
			ft_print_list(begin_a, begin_b, line);
	}
	is_sort(begin_a, begin_b, data);
	return (0);
}
