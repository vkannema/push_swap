/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 13:29:45 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/16 09:58:43 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libftprintf.h"

typedef struct			s_data
{
	int					historic;
	int					color;
	int					mov;
	int					coups;
	int					len;
}						t_data;

typedef struct			s_list_nb
{
	int					nb;
	int					pos;
	struct s_list_nb	*next;
}						t_list_nb;

int						checker(t_list_nb *begin_a, t_list_nb *begin_b,
	t_data *data);
int						handle_error(t_list_nb *begin_a, char **argv,
	t_data *data);
void					put_in_list(int nb, t_list_nb *begin_a, int pos);
void					swap_a(t_list_nb **begin_a, t_data *data);
void					swap_b(t_list_nb **begin_b, t_data *data);
void					reverse_a(t_list_nb **begin_a, t_data *data);
void					rotate_a(t_list_nb **begin_a, t_data *data);
void					rotate_b(t_list_nb **begin_b, t_data *data);
void					reverse_b(t_list_nb **begin_b, t_data *data);
void					push_a(t_list_nb **begin_a, t_list_nb **begin_b,
						t_data *data);
void					push_b(t_list_nb **begin_a, t_list_nb **begin_b,
						t_data *data);
t_list_nb				*ft_lstinit(int nb, int pos);
int						is_sort(t_list_nb *begin_a, t_list_nb *begin_b,
	t_data *data);
void					ft_print_list_complete(t_list_nb *begin_a,
	t_data *data);
void					ft_print_list(t_list_nb *begin_a, t_list_nb *begin_b,
	char *mov);
int						compare_op1(t_list_nb **begin_a, t_list_nb **begin_b,
	t_data *data, char *move);
int						compare_bonus(char *str, t_data *data);
void					ft_free_list(t_list_nb *begin);
#endif
