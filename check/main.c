/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 13:29:28 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/17 14:20:11 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int			compare_bonus(char *str, t_data *data)
{
	if (str[0] == '-')
	{
		if (ft_strchr(str, 'c') != NULL)
			data->color = 1;
		if (ft_strchr(str, 'h') != NULL)
			data->historic = 1;
		if (ft_strchr(str, 'm') != NULL)
			data->mov = 1;
		if (ft_strchr(str, 'l') != NULL)
			data->len = 1;
		if (data->mov == 0 && data->historic == 0 && data->color == 0 &&
			data->len == 0)
			return (2);
		else if (ft_strlen(str) > 4)
			return (2);
		else
			return (1);
	}
	return (0);
}

t_data		*initenv(void)
{
	t_data	*data;

	if (!(data = malloc(sizeof(t_data))))
		return (NULL);
	data->historic = 0;
	data->color = 0;
	data->coups = 0;
	data->mov = 0;
	data->len = 0;
	return (data);
}

void		ft_free_list(t_list_nb *begin)
{
	t_list_nb	*tmp;
	t_list_nb	*tmp2;

	tmp = begin;
	tmp2 = begin;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}

t_list_nb	*complete_list(t_list_nb *begin_a, int i, char **argv, int argc)
{
	begin_a = ft_lstinit(ft_atoi(argv[i]), 1);
	i++;
	while (i < argc)
	{
		put_in_list(ft_atoi(argv[i]), begin_a, i);
		i++;
	}
	return (begin_a);
}

int			main(int argc, char **argv)
{
	int			i;
	t_list_nb	*begin_a;
	t_data		*data;
	t_list_nb	*begin_b;

	i = 1;
	begin_b = NULL;
	begin_a = NULL;
	if (argc < 2)
		return (0);
	data = initenv();
	if (compare_bonus(argv[i], data) == 1)
		i++;
	begin_a = complete_list(begin_a, i, argv, argc);
	if (handle_error(begin_a, argv, data) == 1)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	checker(begin_a, begin_b, data);
	if (data->len && data->color == 0)
		ft_printf("moves %d\n", data->coups);
	ft_memdel((void **)&data);
	return (0);
}
