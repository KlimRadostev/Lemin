/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:02:24 by julee             #+#    #+#             */
/*   Updated: 2019/10/27 20:14:51 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "adjlist.h"

int		queue_len(t_queue *path_q)
{
	t_node	*head;
	int		len;

	if (!path_q || is_empty(path_q))
		return (0);
	head = path_q->first;
	len = 0;
	while (head)
	{
		head = head->next;
		len++;
	}
	return (len);
}

void	fronqueue(t_queue *queue, void *content)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->content = content;
	tmp->next = 0;
	tmp->next = queue->first;
	queue->first = tmp;
	if (is_empty(queue))
		queue->last = tmp;
}

int		*node_alloc(int nodename)
{
	int	*node;

	node = (int *)malloc(sizeof(int));
	*node = nodename;
	return (node);
}

void	ft_swap(void *a, void *b, size_t len)
{
	char	*tmp;

	tmp = malloc(len);
	ft_memmove(tmp, a, len);
	ft_memmove(a, b, len);
	ft_memmove(b, tmp, len);
	free(tmp);
}

void	sort_queue(t_queue *paths)
{
	t_node	*head;
	t_node	*ptr;
	t_node	*end_ptr;
	int		swap;

	head = paths->first;
	end_ptr = 0;
	swap = 1;
	while (swap)
	{
		swap = 0;
		ptr = head;
		while (ptr->next != end_ptr)
		{
			if (queue_len(ptr->content) > queue_len(ptr->next->content))
			{
				ft_swap(ptr, ptr->next, sizeof(ptr));
				swap = 1;
			}
			ptr = ptr->next;
		}
		end_ptr = ptr;
	}
}
