/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:18:40 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/28 19:56:16 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "adjlist.h"
#include "lemin.h"

t_adj_node	*new_adj_list_node(int dest)
{
	t_adj_node *new_node;

	new_node = (t_adj_node*)malloc(sizeof(t_adj_node));
	new_node->dest = dest;
	new_node->r_flow = 1;
	new_node->next = NULL;
	return (new_node);
}

t_graph		*create_graph(int v)
{
	t_graph	*graph;
	int		i;

	graph = (t_graph *)malloc(sizeof(t_graph));
	graph->v = v;
	graph->array = (t_adj_list*)malloc(sizeof(t_adj_list) * v);
	i = -1;
	while (++i < v)
		graph->array[i].head = NULL;
	return (graph);
}

/*
** Add Edge doesn't store the node of the graph
** but rather it just stores the number of the node of the graph
** we might want to change that since it would be good to have info
** on the nodes, will have to restructure everything tho
*/

void		add_edge(t_graph *graph, int src, int dest)
{
	t_adj_node *new_node;

	new_node = new_adj_list_node(dest);
	new_node->next = graph->array[src].head;
	graph->array[src].head = new_node;
	new_node = new_adj_list_node(src);
	new_node->next = graph->array[dest].head;
	graph->array[dest].head = new_node;
}

/*
** void		printGraph(t_graph *graph)
** {
**     for (int v = 0; v < graph->v; ++v)
**     {
**         t_adj_node *pCrawl = graph->array[v].head;
**         ft_printf("\n Adjacency list of vertex %d : ", v);
**         int first = 1;
**         while (pCrawl)
**         {
**             if (first) {
**                 ft_printf("%d", pCrawl->dest);
**                 first = 0;
**             }
**             else
**                 ft_printf(", %d", pCrawl->dest);
**             pCrawl = pCrawl->next;
**         }
**         ft_printf("\n");
**     }
** }
*/

t_graph		*graph_cpy(t_graph *graph)
{
	t_graph		*ret_graph;
	int			i;
	t_adj_node	*tmp;

	ret_graph = create_graph(graph->v);
	i = -1;
	while (++i < graph->v)
	{
		if ((tmp = graph->array[i].head))
			while (tmp)
			{
				add_edge(ret_graph, i, tmp->dest);
				tmp = tmp->next;
			}
	}
	return (ret_graph);
}
