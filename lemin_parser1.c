/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:47:48 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/23 19:55:49 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "lemin.h"

char	*ft_strdelim(char *str, char c)
{
	char	*ret;
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (str[++i] != c && str[i])
		count++;
	if (!(ret = (char *)malloc(sizeof(char) * (count + 1))))
		return ((void *)0);
	i = -1;
	while (++i < count)
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}

char	*ft_strdelim_pos(char *str, char c)
{
	char	*ret;
	int		i;
	int		count;
	int		pos_len;

	i = -1;
	count = 0;
	while (str[++i] != c && str[i])
		count++;
	count++;
	pos_len = ft_strlen(&str[count]);
	if (!(ret = (char *)malloc(sizeof(char) * (pos_len + 1))))
		return ((void *)0);
	i = -1;
	while (++i < pos_len)
		ret[i] = str[count++];
	ret[i] = '\0';
	return (ret);
}

t_data	*init_lemin(void)
{
	t_data	*lemin;

	lemin = (t_data *)malloc(sizeof(t_data));
	lemin->error = 0;
	lemin->start = -1;
	lemin->end = -1;
	lemin->ants = -1;
	lemin->paths = -1;
	lemin->nodes = 0;
	return (lemin);
}

void	free_lemin(t_data *lemin)
{
	int	i;

	i = -1;
	while (++i < lemin->nodes)
		free(lemin->room[i]);
	free(lemin->room);
	free(lemin);
}

void	free_the_deck(t_deck **deck, t_data *lemin)
{
	int		i;
	t_deck	*tmp;

	i = -1;
	while (++i < lemin->paths)
	{
		tmp = deck[i];
		while (!deck_empty(tmp))
			pop_back(tmp);
		free(tmp);
	}
	free(deck);
}
