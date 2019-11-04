/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:44:43 by gaerhard          #+#    #+#             */
/*   Updated: 2019/11/04 14:46:22 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function adds a link to the back of the list
** If the list does not exist yet then it creates it.
*/

void	ft_lstback(t_list **begin_list, void *data, size_t size)
{
	t_list *list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_lstnew(data, size);
	}
	else
		*begin_list = ft_lstnew(data, size);
}