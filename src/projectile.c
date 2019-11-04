/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:23:02 by gaerhard          #+#    #+#             */
/*   Updated: 2019/11/04 16:47:30 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	create_projectile(t_env *env, int sprite, t_v3 pos, t_v3 dest)
{
	t_list	*new;
	t_list	*tmp;

	if (!(new = ft_lstnew(&env->projectile, sizeof(t_projectile))))
		return (ft_printf("Error when creating new projectile\n"));
	ft_lstpushback(&env->projectiles, new);
	tmp = env->projectiles;
	if (tmp)
		ft_printf("1 missile\n");
	//int i = 2;
	while (tmp->next)
	{
		((t_projectile*)tmp->content)->sprite = sprite;
		((t_projectile*)tmp->content)->pos = pos;
		((t_projectile*)tmp->content)->dest = dest;
		//ft_printf("%d missile\n", i++);
		tmp = tmp->next;
	}
	ft_printf("<-------------->\n");
	return (0);
}

