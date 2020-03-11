/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deck2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:09:36 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/23 14:18:42 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "deck.h"

t_deck_node	*deck_node_memory(int room)
{
	t_deck_node	*ret;

	ret = (t_deck_node *)malloc(sizeof(t_deck_node));
	ret->prev = NULL;
	ret->next = NULL;
	ret->room = room;
	ret->ant = 0;
	return (ret);
}

bool		deck_empty(t_deck *deck)
{
	return (!deck->first && !deck->last);
}

t_deck		*deck_init(int len)
{
	t_deck	*tmp;

	tmp = (t_deck *)malloc(sizeof(t_deck));
	tmp->first = NULL;
	tmp->last = NULL;
	tmp->len = len;
	return (tmp);
}

int			pop_front(t_deck *deck)
{
	t_deck_node	*tmp;
	int			ret;

	if (deck_empty(deck))
		return (-1);
	tmp = deck->first;
	ret = deck->first->room;
	deck->first = deck->first->prev;
	if (!deck->first)
	{
		deck->first = 0;
		deck->last = 0;
	}
	else
		deck->first->next = 0;
	tmp->prev = 0;
	free(tmp);
	return (ret);
}

int			pop_back(t_deck *deck)
{
	t_deck_node	*tmp;
	int			ret;

	if (deck_empty(deck))
		return (-1);
	tmp = deck->last;
	ret = deck->last->room;
	deck->last = deck->last->next;
	if (!deck->last)
	{
		deck->last = 0;
		deck->first = 0;
	}
	else
		deck->last->prev = 0;
	tmp->next = 0;
	free(tmp);
	return (ret);
}
