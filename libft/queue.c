/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:58:33 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/17 21:19:14 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "libft.h"

bool	is_empty(t_queue *queue)
{
	return (!queue->first);
}

void	*peek(t_queue *queue)
{
	return (is_empty(queue) ? queue->first->content : 0);
}

t_queue	*queue_init(void)
{
	t_queue *tmp;

	tmp = (t_queue *)malloc(sizeof(t_queue));
	tmp->first = 0;
	tmp->last = 0;
	return (tmp);
}

void	*dequeue(t_queue *queue)
{
	t_node	*tmp;
	void	*ret;

	if (is_empty(queue))
		return (0);
	tmp = queue->first;
	ret = queue->first->content;
	queue->first = queue->first->next;
	if (is_empty(queue))
	{
		queue->first = 0;
		queue->last = 0;
	}
	free(tmp);
	return (ret);
}

void	enqueue(t_queue *queue, void *content)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->content = content;
	tmp->next = 0;
	if (is_empty(queue))
		queue->first = tmp;
	else
		queue->last->next = tmp;
	queue->last = tmp;
}
