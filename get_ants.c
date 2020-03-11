/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:50:56 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/28 21:25:03 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/libft.h"

/*
**STUPID NORMINETTE 27 LINES MAKES ME DO THIS ...
*/

void	get_ants(t_data *lemin)
{
	char	*line;

	get_next_line(0, &line);
	if (!line)
	{
		lemin->error = 7;
		return ;
	}
	ft_putendl(line);
	lemin->ants = ft_atoi(line);
	ft_strdel(&line);
}
