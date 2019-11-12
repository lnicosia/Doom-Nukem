/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:36:19 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/12 19:31:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!new || !alst)
		return ;
	if (!(*alst))
	{
		(*alst) = new;
		(*alst)->next = NULL;
	}
	else
	{
		tmp = (*alst);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
