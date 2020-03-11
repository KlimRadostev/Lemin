/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants_per_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:27:03 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/28 20:27:06 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deck.h"
#include "lemin.h"
#include "libft/libft.h"

static int	get_diff(int *arr, int len, int ants)
{
	int i;
	int res;

	i = len - 1;
	res = 0;
	while (i > 0)
	{
		res += arr[i] - arr[i - 1];
		i--;
	}
	res = ants - res;
	return (res);
}

static void	fill_in_last(int total, int ants, int division, int *ants_arr)
{
	int	i;

	i = 0;
	while (total < ants)
	{
		ants_arr[i]++;
		i++;
		if (i == division - 1)
			i = 0;
		total++;
	}
}

static void	filling_in(int ants, int division, int *ants_arr)
{
	int i;
	int	total;

	i = 0;
	total = 0;
	while (i < division)
		total += ants_arr[i++];
	i = division - 1;
	while (total > ants)
	{
		if (ants_arr[i] != 0)
		{
			ants_arr[i]--;
			total--;
		}
		i--;
		if (i < 0)
			i = division - 1;
	}
	fill_in_last(total, ants, division, ants_arr);
}

static int	*get_ants_for_path(int ants, int *arr, int len)
{
	int division;
	int x;
	int	*ants_arr;
	int	i;
	int	diff;

	division = len;
	x = -1;
	while (x <= 0)
	{
		x = get_diff(arr, division, ants) / division;
		division--;
	}
	ants_arr = (int *)malloc(sizeof(int) * len);
	ft_memset(ants_arr, 0, sizeof(int) * len);
	ants_arr[++division - 1] = x;
	i = division - 1;
	diff = 0;
	while (--i >= 0)
	{
		diff += arr[i + 1] - arr[i];
		ants_arr[i] = x + diff;
	}
	filling_in(ants, division, ants_arr);
	return (ants_arr);
}

int			*get_ant_nest(t_data *lemin, t_deck **deck)
{
	int	*arr_lens;
	int	*ant_nest;
	int	i;

	i = 0;
	arr_lens = (int *)malloc(sizeof(int) * lemin->paths);
	while (i < lemin->paths)
	{
		arr_lens[i] = deck[i]->len;
		i++;
	}
	ant_nest = get_ants_for_path(lemin->ants, arr_lens, lemin->paths);
	free(arr_lens);
	return (ant_nest);
}
