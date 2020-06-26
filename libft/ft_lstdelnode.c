/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:23:37 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/13 17:08:51 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdelnode(t_list **list, t_list *node)
{
	t_list	*prec;
	t_list	*tmp;

	tmp = *list;
	prec = NULL;
	while (tmp)
	{
		if (tmp == node)
		{
			ft_lstpopfront(&tmp);
			if (prec)
				prec->next = tmp;
			else
				*list = tmp;
			return (tmp);
		}
		else
		{
			prec = tmp;
			tmp = tmp->next;
		}
	}
	return (*list);
}
