/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:12:05 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/16 10:29:46 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void		ft_print_a(t_list_nb *begin)
{
	t_list_nb	*tmp;

	tmp = begin;
	while (tmp)
	{
		ft_printf("|%4d|\n", tmp->nb);
		tmp = tmp->next;
	}
	ft_printf("-----\n  A  \n");
}

void		ft_print_list_complete(t_list_nb *begin_a, t_data *data)
{
	t_list_nb	*tmp;

	tmp = begin_a;
	while (tmp)
	{
		ft_printf("{:green}|%4d|      |    |\n", tmp->nb);
		tmp = tmp->next;
	}
	if (!data->len)
		ft_printf("{:green}------      -----\n  A           B   \n\033[0m");
	else
	{
		ft_printf("{:green}------      -----\n  A           B   \n");
		ft_printf("{:green}    moves: %d\n\033[0m",
		data->coups);
	}
}

void		print_norme(t_list_nb *begin_a, t_list_nb *begin_b, int i, int j)
{
	t_list_nb	*tmp;
	t_list_nb	*tmpb;

	tmp = begin_a;
	tmpb = begin_b;
	while (j > i)
	{
		ft_printf("|    |      |%4d|\n", tmpb->nb);
		tmpb = tmpb->next;
		j--;
	}
	while (i > j)
	{
		ft_printf("|%4d|\n", tmp->nb);
		tmp = tmp->next;
		i--;
	}
	while (tmp && tmpb)
	{
		ft_printf("|%4d|      ", tmp->nb);
		ft_printf("|%4d|\n", tmpb->nb);
		tmpb = tmpb->next;
		tmp = tmp->next;
	}
}

static int	lstlen_a(t_list_nb *begin)
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

void		ft_print_list(t_list_nb *begin_a, t_list_nb *begin_b, char *mov)
{
	int	i;
	int	j;

	i = lstlen_a(begin_a);
	j = lstlen_a(begin_b);
	print_norme(begin_a, begin_b, i, j);
	ft_printf("------      -----\n  A    [%.3s]     B   \n\n", mov);
}
