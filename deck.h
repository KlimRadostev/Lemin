/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deck.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:17:17 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/23 15:50:07 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECK_H
# define DECK_H

# include <stdbool.h>

typedef struct	s_deck_node
{
	int					ant;
	int					room;
	struct s_deck_node	*next;
	struct s_deck_node	*prev;
}				t_deck_node;

typedef struct	s_deck
{
	int			len;
	t_deck_node	*first;
	t_deck_node	*last;
}				t_deck;

t_deck_node		*deck_node_memory(int room);
bool			deck_empty(t_deck *deck);
int				peak_front(t_deck *deck);
int				peak_back(t_deck *deck);
t_deck			*deck_init(int len);
void			push_front(t_deck *deck, int value);
void			push_back(t_deck *deck, int value);
int				pop_front(t_deck *deck);
int				pop_back(t_deck *deck);

#endif
