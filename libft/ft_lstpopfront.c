/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:27:54 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/08 17:46:11 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpopfront(t_list **alst)
{
	t_list	*new;

	if (!alst)
		return ;
	new = (*alst)->next;
	if ((*alst)->content)
		free((*alst)->content);
	free(*alst);
	*alst = new;
}
