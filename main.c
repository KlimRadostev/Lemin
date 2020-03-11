/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:18:40 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/28 21:24:53 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "lemin.h"
#include "dictionary.h"
#include "adjlist.h"
#include "deck.h"

#include "libft/libft.h"

/*
**USEFUL CODE BUT WE ARE NOT USING IT
**void	delete_node_from_list(t_graph *graph, int y, t_AdjNode *list, int x)
**{
**	t_AdjNode	*tmp;*
**
**	tmp = list;
**	if (list && list->dest == x)
**	{
**		list = list->next;
**		graph->array[y].head = list;
**		free(tmp);
**		return ;
**	}
**	if (tmp && tmp->next)
**		tmp = tmp->next;
**	else
**		return ;
**	while (tmp->dest != x && tmp->next)
**	{
**		list = list->next;
**		tmp = tmp->next;
**	}
**	if (tmp->dest == x)
**	{
**		list->next = tmp->next;
**		free(tmp);
**	}
**	return ;
**}
**
**
**void	delete_graph_path(t_graph *graph, t_queue *path)
**{
**	t_node		*tmp;
**	t_AdjNode	*list;
**	t_AdjNode	*del;
**	int			x;
**	int			y;
**
**	tmp = path->first;
**	x = *((int *)tmp->content);
**	list = graph->array[x].head;
**	y = *((int *)tmp->next->content);
**	delete_node_from_list(graph, x, list, y);
**	tmp = tmp->next;
**	while (tmp && tmp->next)
**	{
**		x = *((int *)tmp->content);
**		list = graph->array[x].head;
**		while (list)
**		{
**			y = list->dest;
**			del = graph->array[y].head;
**			delete_node_from_list(graph, y, del, x);
**			list = list->next;
**		}
**		list = graph->array[x].head;
**		graph->array[x].head = NULL;
**		while (list)
**		{
**			del = list;
**			list = list->next;
**			free(del);
**		}
**		tmp = tmp->next;
**	}
**	list = graph->array[y].head;
**	delete_node_from_list(graph, y, list, x);
**}
**
**NOT GONNA USE THIS FUNCTION
**bool	best_path_flow(t_data *lemin, t_queue *paths1, t_queue *paths2)
**{
**	double	p1;
**	double	p2;
**	t_node	*path_trace1;
**	t_node	*path_trace2;
**	int		ants;
**
**	p1 = 0;
**	p2 = 0;
**	ants = -1;
**	path_trace1 = paths1->first;
**	path_trace2 = paths2->first;
**	while (++ants < lemin->ants)
**	{
**		p1 += queue_len(path_trace1->content);
**		p2 += queue_len(path_trace2->content);
**		path_trace1 = path_trace1->next;
**		path_trace2 = path_trace2->next;
**	}
**	p1 /= lemin->ants;
**	p2 /= lemin->ants;
**	return ((p1 > p2) ? 1 : 0);
**}
*/

static int		error_logs(int error)
{
	if (error == 0)
		ft_printf("no error code problem\n");
	else if (error == 1)
		ft_printf("program error 1: no nodes in program\n");
	else if (error == 2)
		ft_printf("program error 2: not enough ants\n");
	else if (error == 3)
		ft_printf("program error 3: start or end was not set in input file\n");
	else if (error == 4)
		ft_printf("program error 4: link not found\n");
	else if (error == 5)
		ft_printf("program error 5: no paths were found\n");
	else if (error == 6)
		ft_printf("program error 6: syntax error\n");
	else if (error == 7)
		ft_printf("program error 7: nothing in file\n");
	return (1);
}

static t_deck	**convert_to_custom_deck(t_queue *flow, int caminos)
{
	t_deck	**deck;
	int		i;
	t_queue	*path;
	int		*p;

	if (!(deck = (t_deck **)malloc(sizeof(t_deck) * caminos)))
		return (NULL);
	i = 0;
	while (!is_empty(flow))
	{
		path = dequeue(flow);
		deck[i] = deck_init(queue_len(path));
		while (!is_empty(path))
		{
			p = dequeue(path);
			push_back(deck[i], *p);
			free(p);
		}
		free(path);
		i++;
	}
	free(flow);
	return (deck);
}

static int		print_and_push(t_data *lemin, t_deck **deck, int caminos, int i)
{
	t_deck_node	*go_back;
	int			key;
	int			first;

	key = 0;
	first = 1;
	while (++i < caminos)
	{
		go_back = deck[i]->last;
		while (go_back)
		{
			if (go_back->next && go_back->next->ant)
			{
				go_back->ant = go_back->next->ant;
				go_back->next->ant = 0;
				if (!first)
					ft_putchar(' ');
				ft_printf("L%d-%s", go_back->ant, lemin->room[go_back->room]);
				key = 1;
				first = 0;
			}
			go_back = go_back->next;
		}
	}
	return (key);
}

static void		print_path(t_data *lemin, t_queue *flow)
{
	t_deck	**deck;
	int		*ant_nest;
	int		ants;
	int		i;
	int		first;

	first = 1;
	ants = lemin->ants;
	deck = convert_to_custom_deck(flow, lemin->paths);
	ant_nest = get_ant_nest(lemin, deck);
	while (ants > 0)
	{
		print_and_push(lemin, deck, lemin->paths, -1);
		i = -1;
		while (++i < lemin->paths && ant_nest[i]-- > 0)
			deck[i]->first->ant = (lemin->ants - ants--) + 1;
		if (!first)
			ft_putchar('\n');
		first = 0;
	}
	while (print_and_push(lemin, deck, lemin->paths, -1))
		ft_putchar('\n');
	free(ant_nest);
	free_the_deck(deck, lemin);
}

int				main(void)
{
	t_dict	*dict;
	t_data	*lemin;
	t_graph	*graph;
	t_queue *flow;

	lemin = init_lemin();
	dict = dict_init(6000);
	graph = parse_lemin_dictionary(lemin, dict);
	free_dict(dict);
	ft_putchar('\n');
	if (lemin->error != 0 && error_logs(lemin->error))
		return (1);
	flow = get_max_flow(graph, lemin->start, lemin->end);
	lemin->paths = queue_len(flow);
	if (lemin->paths <= 0)
		lemin->error = 5;
	if (lemin->error != 0 && error_logs(lemin->error))
		return (1);
	sort_queue(flow);
	print_path(lemin, flow);
	free_graph(graph);
	free_lemin(lemin);
	return (0);
}
