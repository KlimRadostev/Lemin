/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_parser2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:07:16 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/28 21:36:06 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "lemin.h"
#include "dictionary.h"
#include "adjlist.h"

#include "libft/libft.h"

static void	parse_graph(t_data *lemin, t_graph *graph, t_dict *dict, char *line)
{
	t_dict_node	*node1;
	t_dict_node	*node2;
	char		*str1;
	char		*str2;

	if (line[0] != '#')
	{
		str1 = ft_strdelim(line, '-');
		str2 = ft_strdelim_pos(line, '-');
		node1 = dict_search(dict, str1);
		node2 = dict_search(dict, str2);
		if (!node1 || !node2)
			lemin->error = 4;
		else
			add_edge(graph, node1->id, node2->id);
		free(str1);
		free(str2);
	}
}

static void	parse_dict(t_data *lemin, t_dict *dict, char *line, t_queue *room)
{
	static int	key;
	t_dict_node	*val;
	char		*str;

	if (!ft_strcmp(line, "##start"))
		key = 1;
	else if (!ft_strcmp(line, "##end"))
		key = -1;
	else if (line[0] != '#')
	{
		if (key == -1 && !++key)
			lemin->end = lemin->nodes;
		if (key == 1 && !--key)
			lemin->start = lemin->nodes;
		val = (t_dict_node *)malloc(sizeof(t_dict_node));
		str = ft_strdelim(line, ' ');
		val->name = str;
		val->id = lemin->nodes++;
		enqueue(room, ft_strdup(val->name));
		dict_insert(dict, str, val);
	}
}

static void	set_rooms(t_data *lemin, t_queue *room_names)
{
	int	i;

	i = -1;
	lemin->room = (char **)malloc(sizeof(char *) * lemin->nodes);
	while (++i < lemin->nodes)
		lemin->room[i] = dequeue(room_names);
}

static void	error_checker_and_set_room(t_data *lemin, t_queue *room_names)
{
	if (lemin->error == 7)
		return ;
	if (lemin->start < 0 || lemin->end < 0)
		lemin->error = 3;
	if (lemin->nodes == 0)
		lemin->error = 1;
	if (lemin->ants <= 0)
		lemin->error = 2;
	set_rooms(lemin, room_names);
	free(room_names);
}

t_graph		*parse_lemin_dictionary(t_data *lemin, t_dict *dict)
{
	t_graph		*graph;
	char		*line;
	int			link_key;
	t_queue		*room_names;

	room_names = queue_init();
	get_ants(lemin);
	if (!(link_key = 0) && lemin->error == 7)
		return (NULL);
	while (get_next_line(0, &line))
	{
		ft_putendl(line);
		if (link_key == 0 && !ft_strchr(line, '-'))
			parse_dict(lemin, dict, line, room_names);
		else
		{
			if (link_key == 0)
				graph = create_graph(lemin->nodes);
			parse_graph(lemin, graph, dict, line);
			link_key = 1;
		}
		ft_strdel(&line);
	}
	error_checker_and_set_room(lemin, room_names);
	return (graph);
}
