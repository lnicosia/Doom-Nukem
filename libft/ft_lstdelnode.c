/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:23:37 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/13 16:27:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelnode(t_list **list, t_list *node)
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
			}
			else
			{
				prec = tmp;
				tmp = tmp->next;
			}
		}
}
