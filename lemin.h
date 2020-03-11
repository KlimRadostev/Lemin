/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:55:11 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/28 19:58:33 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "dictionary.h"
# include "adjlist.h"
# include "deck.h"

# include "libft/libft.h"

typedef struct	s_data
{
	int		error;
	int		nodes;
	int		start;
	int		end;
	int		ants;
	int		paths;
	char	**room;
}				t_data;

/*
** FOR NORM REASONS STRUCT
*/

typedef struct	s_augment
{
	int			*visited;
	int			*node_ptr;
	int			ret;
	t_queue		*traverse;
	t_adj_node	*head;
}				t_augment;

void			get_ants(t_data *lemin);
int				get_node_amount(char *file, t_data *lemin);
t_data			*init_lemin();
t_graph			*parse_lemin_dictionary(t_data *lemin, t_dict *dict);
void			free_the_deck(t_deck **deck, t_data *lemin);
void			free_lemin(t_data *lemin);
int				*get_ant_nest(t_data *lemin, t_deck **deck);

/*
** ALGORITHMS
*/
t_queue			*find_shortest_path(t_graph *graph, int start, int end);
t_queue			*get_max_flow(t_graph *graph, int start, int end);

/*
** HELPER FUNCTIONS
*/
char			*ft_strdelim(char *str, char c);
char			*ft_strdelim_pos(char *str, char c);
int				queue_len(t_queue *path_q);
void			fronqueue(t_queue *queue, void *content);
int				*node_alloc(int nodename);
void			sort_queue(t_queue *paths);

#endif
