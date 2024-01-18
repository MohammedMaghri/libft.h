/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_for_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:13:51 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/18 16:54:19 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int bring_last(t_Node **list)
{
	t_Node *last;
	int num ;

	last = (*list);
	while (last->next->next != NULL)
		last = last ->next;
	last = last->next;
	num = last->array ;
	return (num);
}
void push_positiong(t_Node **list, t_Node **list_b)
{
	int small ;

	if (count_list(*list) == 3)
	{
		printf("inside----");
		check_tree(list);
		return ;
	}
	if (count_list(*list) == 4)
	{
		check_four(list, list_b);
		return ;
	}
	while (count_list(*list) > 3)
	{
		small = check_less(list);
		if (small == 1)
			pb_push(list, list_b);
		else if (small == 2)
			ra_rotate(list);
		else if (small == 3)
			rra_rotate(list);
		else if (small == 4)
			rra_rotate(list);
		else if (small == 5)
			rra_rotate(list);
	}
	check_tree(list);
	pa_push(list, list_b);
	pa_push(list, list_b);
}
void check_four(t_Node **list, t_Node **list_b)
{
	int small;

	while (count_list(*list) > 3)
	{
		small = check_less(list);
		if (small == 1)
			pb_push(list, list_b);
		else if (small == 2)
			ra_rotate(list);
		else if (small == 3)
			rra_rotate(list);
		else if (small == 4)
			rra_rotate(list);
		else if (small == 5)
			rra_rotate(list);
	}
	check_tree(list);
	pa_push(list, list_b);
}
void check_tree(t_Node **list)
{
	int	this;

	if (check_sort((list)) == 0)
	{
		printf("Sorted");
		return ;
	}
	this = check_highest(list);
	printf("this ==== %d\n", this);
	if (count_list(*list) == 2)
		{
			if (check_sort(list) == -1)
				sa_swap(*list);
			return ;
		}
	else if (this == 0)
	{
		printf("count 0");
		ra_rotate(list);
		if (check_sort(list) == -1)
			sa_swap(*list);
		return ;
	}
	else if (this == 1)
	{
		rra_rotate(list);
		if (check_sort(list) == -1)
			sa_swap(*list);
		return ;
	}
	else if (this == 2)
	{
		if (check_sort(list) == -1)
			sa_swap(*list);
		return ;
	}
}