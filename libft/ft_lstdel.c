/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:28:11 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/07 13:52:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*nxt;

	tmp = *alst;
	if (alst == NULL)
		return ;
	while (tmp != NULL)
	{
		nxt = tmp->next;
		ft_lstdelone(&tmp, del);
		tmp = nxt;
	}
	*alst = NULL;
}
