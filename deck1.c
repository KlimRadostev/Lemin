/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deck.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:24:38 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/23 19:57:56 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deck.h"

int			peak_front(t_deck *deck)
{
	return (!deck_empty(deck) ? deck->first->room : -1);
}

int			peak_back(t_deck *deck)
{
	return (!deck_empty(deck) ? deck->last->room : -1);
}

void		push_front(t_deck *deck, int room)
{
	t_deck_node	*tmp;

	tmp = deck_node_memory(room);
	if (deck_empty(deck))
	{
		deck->first = tmp;
		deck->last = tmp;
		tmp->next = 0;
		tmp->prev = 0;
	}
	else
	{
		tmp->prev = deck->first;
		deck->first->next = tmp;
		tmp->next = 0;
		deck->first = tmp;
	}
}

void		push_back(t_deck *deck, int room)
{
	t_deck_node	*tmp;

	tmp = deck_node_memory(room);
	if (deck_empty(deck))
	{
		deck->first = tmp;
		deck->last = tmp;
		tmp->next = 0;
		tmp->prev = 0;
	}
	else
	{
		tmp->next = deck->last;
		deck->last->prev = tmp;
		tmp->prev = 0;
		deck->last = tmp;
	}
}
