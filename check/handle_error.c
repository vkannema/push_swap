/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:35:08 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/15 17:32:35 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	handle_wrong_arg(char **argv, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (ft_strlen(argv[i]) > 10 || ft_atoi(argv[i]) > 2147483647 ||
		ft_atoi(argv[i]) < -2147483648)
			return (1);
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else if (compare_bonus(argv[i], data) == 1 && i == 1)
				break ;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	handle_error(t_list_nb *begin_a, char **argv, t_data *data)
{
	t_list_nb *tmp;
	t_list_nb *tmp2;

	tmp = begin_a;
	if (handle_wrong_arg(argv, data) == 1)
		return (1);
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->nb > 2147483646 || tmp2->nb < -2147483648)
				return (1);
			if (tmp2->nb == tmp->nb)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
