/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:06:47 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/27 21:28:16 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/libft.h"
#include "adjlist.h"

/*
**USEFUL CODE BUT WE ARENT USING IT
**t_queue	*find_shortest_path(t_graph *graph, int start, int end) {
**
**	t_adj_node *head;
**	t_queue *main_q = queue_init();
**	t_queue *path_q = queue_init();
**	int tmp = start;
**	enqueue(path_q, &tmp);
**	enqueue(main_q, path_q);
**
**	while (!is_empty(main_q)) {
**		path_q = dequeue(main_q);
**		int *node = path_q->last->content;
**		if (end == *node) {
**			return path_q;
**		}
**		int q_len = queue_len(path_q);
**		int *tmp = (int *)malloc(sizeof(int) * q_len);
**		int i = 0;
**		while(!is_empty(path_q)) {
**			int *p = dequeue(path_q);
**			tmp[i++] = *p;
**		}
**		head = graph->array[*node].head;
**		while (head) {
**			i = -1;
**			t_queue *new_path = queue_init();
**			while (++i < q_len) {
**				enqueue(new_path, &tmp[i]);
**			}
**			int *p = malloc(sizeof(int));
**			*p = head->dest;
**			enqueue(new_path, p);
**			enqueue(main_q, new_path);
**			head = head->next;
**		}
**	}
**	return 0;
**}
*/

void		set_visited(int **visited, int v, int start, int *parent)
{
	int i;

	*visited = (int *)malloc(sizeof(int) * v);
	i = -1;
	while (++i < v)
		(*visited)[i] = 0;
	(*visited)[start] = true;
	parent[start] = -1;
}

bool		augment_flow(t_graph *r_graph, int start, int end, int *parent)
{
	t_augment ag;

	set_visited(&(ag.visited), r_graph->v, start, parent);
	ag.traverse = queue_init();
	enqueue(ag.traverse, node_alloc(start));
	while (!is_empty(ag.traverse))
	{
		ag.node_ptr = dequeue(ag.traverse);
		ag.head = r_graph->array[*(ag.node_ptr)].head;
		while (ag.head)
		{
			if (ag.visited[ag.head->dest] == false && ag.head->r_flow > 0)
			{
				enqueue(ag.traverse, node_alloc(ag.head->dest));
				parent[ag.head->dest] = *(ag.node_ptr);
				ag.visited[ag.head->dest] = true;
			}
			ag.head = ag.head->next;
		}
		free(ag.node_ptr);
	}
	ag.ret = ag.visited[end];
	free(ag.visited);
	free(ag.traverse);
	return (ag.ret);
}

static void	draw_residual(t_queue *path, int *i, int *parent, t_graph *r_graph)
{
	int			node;
	t_adj_node	*head;

	fronqueue(path, node_alloc(*i));
	node = parent[*i];
	head = r_graph->array[node].head;
	while (head)
	{
		if (head->dest == *i)
			head->r_flow = -1;
		head = head->next;
	}
	*i = parent[*i];
}

t_queue		*get_max_flow(t_graph *graph, int start, int end)
{
	t_graph		*r_graph;
	t_queue		*path_q;
	t_queue		*path;
	int			*parent;
	int			i;

	if (!graph->array[start].head)
		return (NULL);
	r_graph = graph_cpy(graph);
	parent = (int *)malloc(sizeof(int) * graph->v);
	path_q = queue_init();
	while (augment_flow(r_graph, start, end, parent))
	{
		path = queue_init();
		i = end;
		while (i != start)
			draw_residual(path, &i, parent, r_graph);
		fronqueue(path, node_alloc(start));
		enqueue(path_q, path);
	}
	free_graph(r_graph);
	free(parent);
	return (path_q);
}
