/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:27:39 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/28 15:48:59 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_list(t_list *list)
{
	t_list *next;

	while (list != NULL)
	{
		next = list->next;
		free(list);
		list = next;
	}
	return (NULL);
}
