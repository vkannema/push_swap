/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:56:15 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/15 18:26:21 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	compare_op2(t_list_nb **begin_a, t_list_nb **begin_b, t_data *data,
	char *move)
{
	if (ft_strnstr(move, "ra", 2) && ft_strlen(move) < 3)
	{
		rotate_a(begin_a, data);
		return (0);
	}
	else if (ft_strnstr(move, "rb", 2) && ft_strlen(move) < 3)
	{
		rotate_b(begin_b, data);
		return (0);
	}
	else if (ft_strnstr(move, "rra", 3) && ft_strlen(move) < 4)
	{
		reverse_a(begin_a, data);
		return (0);
	}
	else if (ft_strnstr(move, "rrb", 3) && ft_strlen(move) < 4)
	{
		reverse_b(begin_b, data);
		return (0);
	}
	return (1);
}

int			compare_op1(t_list_nb **begin_a, t_list_nb **begin_b, t_data *data,
	char *move)
{
	if (compare_op2(begin_a, begin_b, data, move) == 0)
		return (0);
	else if (ft_strnstr(move, "rr", 2) && ft_strlen(move) < 3)
	{
		rotate_a(begin_a, data);
		rotate_b(begin_b, data);
		return (0);
	}
	else if (ft_strnstr(move, "rrr", 3) && ft_strlen(move) < 4)
	{
		reverse_a(begin_a, data);
		reverse_b(begin_b, data);
		return (0);
	}
	else if (ft_strnstr(move, "pb", 2) && ft_strlen(move) < 3)
	{
		push_b(begin_a, begin_b, data);
		return (0);
	}
	else if (ft_strnstr(move, "pa", 2) && ft_strlen(move) < 3)
	{
		push_a(begin_a, begin_b, data);
		return (0);
	}
	return (1);
}
