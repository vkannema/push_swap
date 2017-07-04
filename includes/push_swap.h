/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:40:32 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/17 14:14:01 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "libftprintf.h"

typedef struct			s_list_nb
{
	int					nb;
	int					pos;
	struct s_list_nb	*next;
}						t_list_nb;

typedef struct			s_data
{
	int					*array;
	int					*quart;
}						t_data;

t_list_nb				*ft_lstinit(int nb, int pos);
t_list_nb				*ft_lstinitb();
int						lstlen_a(t_list_nb *begin);
void					put_in_list(int nb, t_list_nb *begin_a, int pos);
void					swap_a(t_list_nb **begin_a);
void					swap_b(t_list_nb **begin_b);
void					reverse_a(t_list_nb **begin_a);
void					rotate_a(t_list_nb **begin_a);
void					rotate_b(t_list_nb **begin_b);
void					reverse_b(t_list_nb **begin_b);
void					push_a(t_list_nb **begin_a, t_list_nb **begin_b);
void					push_b(t_list_nb **begin_a, t_list_nb **begin_b);
int						ft_pushswap(t_list_nb *begin_a, t_data *data);
void					ft_print_a(t_list_nb *begin);
int						ft_is_dec(t_list_nb *begin);
int						ft_is_croi(t_list_nb *begin);
int						ft_get_max(t_list_nb *begin);
int						ft_get_min(t_list_nb *begin);
int						ft_get_under(t_list_nb *begin_a, int av);
int						ft_find_next(t_list_nb *begin, int nb, int *array);
int						ft_find_previous(t_list_nb *begin, int nb, int *array);
int						ft_get_median(t_list_nb *begin);
int						get_quart_a(t_list_nb *begin, t_data *data, int len);
int						ft_define_shorter(t_list_nb *elem, int len, int pos);
t_list_nb				*ft_go_last(t_list_nb *begin_a);
void					quicksort(int *array, int start, int end);
t_list_nb				*ft_for_3(t_list_nb *begin_a, t_data *data);
t_list_nb				*ft_for_more(t_list_nb *begin_a, t_list_nb *begin_b,
	t_data *data, int len);
int						big_lists(t_list_nb *begin_a, t_list_nb *begin_b,
	t_data *data);
int						ft_get_closer_down(t_list_nb *begin_b);
int						ft_get_closer_up(t_list_nb *begin_b);
int						ft_get_closer_down_med(t_list_nb *begin, int median);
int						ft_get_closer_up_med(t_list_nb *begin_b, int median);
void					ft_free_list(t_list_nb *begin);
int						handle_error(t_list_nb *begin_a, char **argv);
int						*split_array(t_list_nb *begin);
#endif
