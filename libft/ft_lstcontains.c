/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcontains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:09:59 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/21 15:19:46 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcontains(t_list *lst, void *content)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->content == content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
