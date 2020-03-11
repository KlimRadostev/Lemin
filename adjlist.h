/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:11:08 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/23 15:55:59 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADJLIST_H
# define ADJLIST_H

typedef struct	s_adj_node
{
	int					dest;
	int					r_flow;
	struct s_adj_node	*next;
}				t_adj_node;

typedef struct	s_adj_list
{
	t_adj_node	*head;
}				t_adj_list;

typedef struct	s_graph
{
	int			v;
	t_adj_list	*array;
}				t_graph;

t_adj_node		*new_ad_list_node(int dest);
t_graph			*create_graph(int v);
void			add_edge(t_graph *graph, int src, int dest);
void			copy_elem(t_adj_node *dst, t_adj_node *src);
t_graph			*graph_cpy(t_graph *graph);
void			free_graph(t_graph *graph);
/*
** void			printGraph(t_graph *graph);
*/

#endif
